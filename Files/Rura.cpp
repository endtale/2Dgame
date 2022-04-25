#include "Rura.h"
namespace Moje
{
	Rura::Rura(DG dane) : _dane(dane)
	{
		_wysokosc = 160;
		_dane->aktyw.ladujTeksture("Rura", RURA_LOKALIZACJA);
		_spriteRura.setTexture(this->_dane->aktyw.GetTexture("Rura"));
		_spriteRura.setPosition(-200, _wysokosc);
	}

	void Rura::RuraAnimuj()
	{
		float szybkosc;

		if ((_spriteRura.getPosition().x < TYL_MAPY) && (Keyboard::isKeyPressed(Keyboard::Right)))
		{
			_spriteRura.setPosition(TYL_MAPY, _wysokosc);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			szybkosc = 0 - SZYBKOSC_PORUSZANIA_ELEMENTY;

			_spriteRura.move(szybkosc, 0.0f);
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			szybkosc = SZYBKOSC_PORUSZANIA_ELEMENTY;

			_spriteRura.move(szybkosc, 0.0f);
		}
	}

	void Rura::RuraRysuj()
	{
		_dane->okno.draw(_spriteRura);
	}
 }