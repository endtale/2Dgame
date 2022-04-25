#include "Pêtla.h"
#include "Logo.h"

namespace Moje
{
	Gra::Gra(int szer, int wys, string tytul)
	{
		_dane->okno.create(VideoMode(szer, wys), tytul, Style::Close | Style::Titlebar);

		_dane->okno.setFramerateLimit(240);

		_dane->maszyna.DodajStan(SR(new Logo(this->_dane)), true);
		

		this->Uruchom();
	}

	void Gra::Uruchom()
	{
		float czasNowy, czasKadr, interpolacja;

		float czasTeraz = this->_zegar.getElapsedTime().asSeconds();
		float akumulator = 0.0f;

		while (this->_dane->okno.isOpen())
		{
			this->_dane->maszyna.ProcesZmianStanu();

			czasNowy = this->_zegar.getElapsedTime().asSeconds();
			czasKadr = czasNowy - czasTeraz;

			if (czasKadr > 0.25f)
			{
				czasKadr = 0.25f;
			}

			czasTeraz = czasNowy;
			akumulator += czasKadr;

			while (akumulator >= delta)
			{
				this->_dane->maszyna.GetActiveState()->OgarnijWejscie();
				this->_dane->maszyna.GetActiveState()->Aktualizuj(delta);
				akumulator -= delta;
			}

			interpolacja = akumulator / delta;
			this->_dane->maszyna.GetActiveState()->Rysuj(interpolacja);
		}
	}
}
