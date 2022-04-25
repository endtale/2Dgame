#define _CRT_SECURE_NO_WARNINGS
#include "Logo.h"
#include "Definicje.h"
#include "G³ówneMenu.h"
#include <sstream>
#include <iostream>



namespace Moje
{
	Logo::Logo(DG dane) : _dane(dane)
	{

	}

	void Logo::Inicjalizacja()
	{
		_dane->aktyw.ladujTeksture("Logo Tlo", LOGO_LOKALIZACJA);

		_tlo.setTexture(this->_dane->aktyw.GetTexture("Logo Tlo"));

		_dane->wejscie.odczytPocz("wynikiLatwy.dat");
		_dane->wejscie.odczytPocz("wynikiSredni.dat");
		_dane->wejscie.odczytPocz("wynikiTrudny.dat");
		_dane->wejscie.odczytPocz("Zapis1.dat");
		_dane->wejscie.odczytPocz("Zapis2.dat");
		_dane->wejscie.odczytPocz("Zapis3.dat");
	}

	void Logo::OgarnijWejscie()
	{
		Event event;

		while (_dane->okno.pollEvent(event))
		{
			if (Event::Closed == event.type)
			{
				_dane->okno.close();
			}
		}
	}

	void Logo::Aktualizuj(float delta)
	{
		if (_zegar.getElapsedTime().asSeconds() > LOGO_CZAS)
		{
			_dane->maszyna.DodajStan(SR(new MenuGlowne(_dane)), true);
		}
	}

	void Logo::Rysuj(float delta)
	{
		_dane->okno.clear();
		_dane->okno.draw(_tlo);
		_dane->okno.display();
	}
}

