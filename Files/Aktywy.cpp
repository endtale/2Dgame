#include "Aktywy.h"

namespace Moje
{
	void Aktywy::ladujTeksture(string nazwa, string plik)
	{
		Texture tekstura;

		if (tekstura.loadFromFile(plik))
		{
			this->_tekstury[nazwa] = tekstura;
		}
	}

	Texture &Aktywy::GetTexture(string nazwa)
	{
		return this->_tekstury.at(nazwa);
	}

///////////////////////////////////////////////////////////////////

	void Aktywy::ladujCzcionke(string nazwa, string plik)
	{
		Font czcionka;

		if (czcionka.loadFromFile(plik))
		{
			this->_czcionki[nazwa] = czcionka;
		}
	}

	Font &Aktywy::GetFont(string nazwa)
	{
		return this->_czcionki.at(nazwa);
	}
}