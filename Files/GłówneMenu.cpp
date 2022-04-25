#include "G³ówneMenu.h"

#include <sstream>
#include <iostream>

namespace Moje
{
	MenuGlowne::MenuGlowne(DG dane) : _dane(dane)
	{
		flaga = false;
		flaga2 = false;
		flaga3 = false;
		wyjscieZnacznik = false;
	}

	void MenuGlowne::Inicjalizacja()
	{
		_dane->aktyw.ladujTeksture("Menu Tlo", MENU_TLO_LOKALIZACJA);
		_tlo.setTexture(this->_dane->aktyw.GetTexture("Menu Tlo"));

		_dane->aktyw.ladujTeksture("Menu Tytul", MENU_TYTUL_LOKALIZACJA);
		_tytul.setTexture(this->_dane->aktyw.GetTexture("Menu Tytul"));
		_tytul.setPosition((SZER_OKNA /2) - (_tytul.getGlobalBounds().width/2), _tytul.getGlobalBounds().height/10);

		_dane->aktyw.ladujTeksture("Menu Graj", MENU_GRAJ_LOKALIZACJA);
		_grajPrzycisk.setTexture(this->_dane->aktyw.GetTexture("Menu Graj"));
		_grajPrzycisk.setPosition((SZER_OKNA / 5) - (_grajPrzycisk.getGlobalBounds().width / 2), (WYS_OKNA/2) + (_grajPrzycisk.getGlobalBounds().height/1.5));

		_dane->aktyw.ladujTeksture("Menu Graj2", MENU_GRAJ_NACISNIETY_LOKALIZACJA);
		_grajPrzycisk2.setTexture(this->_dane->aktyw.GetTexture("Menu Graj2"));
		_grajPrzycisk2.setPosition((SZER_OKNA / 5) - (_grajPrzycisk2.getGlobalBounds().width / 2), (WYS_OKNA / 2) + (_grajPrzycisk2.getGlobalBounds().height / 1.5));

		_dane->aktyw.ladujTeksture("Menu Zapisz", MENU_ZAPISZ_LOKALIZACJA);
		_zapisyPrzycisk.setTexture(this->_dane->aktyw.GetTexture("Menu Zapisz"));
		_zapisyPrzycisk.setPosition((SZER_OKNA / 2) - (_zapisyPrzycisk.getGlobalBounds().width / 2), (WYS_OKNA / 2) + (_zapisyPrzycisk.getGlobalBounds().height / 1.5));

		_dane->aktyw.ladujTeksture("Menu Zapisz2", MENU_ZAPISZ_NACISNIETY_LOKALIZACJA);
		_zapisyPrzycisk2.setTexture(this->_dane->aktyw.GetTexture("Menu Zapisz2"));
		_zapisyPrzycisk2.setPosition((SZER_OKNA / 2) - (_zapisyPrzycisk2.getGlobalBounds().width / 2), (WYS_OKNA / 2) + (_zapisyPrzycisk2.getGlobalBounds().height / 1.5));

		_dane->aktyw.ladujTeksture("Menu Wyniki", MENU_WYNIKI_LOKALIZACJA);
		_wynikiPrzycisk.setTexture(this->_dane->aktyw.GetTexture("Menu Wyniki"));
		_wynikiPrzycisk.setPosition(800 -(SZER_OKNA / 5) - (_wynikiPrzycisk.getGlobalBounds().width / 2), (WYS_OKNA / 2) + (_wynikiPrzycisk.getGlobalBounds().height / 1.5));

		_dane->aktyw.ladujTeksture("Menu Wyniki2", MENU_WYNIKI_NACISNIETY_LOKALIZACJA);
		_wynikiPrzycisk2.setTexture(this->_dane->aktyw.GetTexture("Menu Wyniki2"));
		_wynikiPrzycisk2.setPosition(800 - (SZER_OKNA / 5) - (_wynikiPrzycisk2.getGlobalBounds().width / 2), (WYS_OKNA / 2) + (_wynikiPrzycisk2.getGlobalBounds().height / 1.5));

		_dane->aktyw.ladujTeksture("Wyjscie1", WYJSCIE_1_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Wyjscie2", WYJSCIE_2_LOKALIZACJA);
		_wyjscie1.setTexture(_dane->aktyw.GetTexture("Wyjscie1"));
		_wyjscie2.setTexture(_dane->aktyw.GetTexture("Wyjscie2"));
		_wyjscie1.setPosition(SZER_OKNA  - _wyjscie1.getGlobalBounds().width, 0);
		_wyjscie2.setPosition(SZER_OKNA  - _wyjscie1.getGlobalBounds().width, 0);
	}

	void MenuGlowne::OgarnijWejscie()
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

	void MenuGlowne::Aktualizuj(float delta)
	{	
		if (zegar.getElapsedTime().asSeconds() > 0.15)
		{
			if (_dane->wejscie.CzyNajechany(_grajPrzycisk, _dane->okno))
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					_dane->maszyna.DodajStan(SR(new Poziom(_dane)), true);
				}
				flaga = true;
			}
			else
			{
				flaga = false;
			}
			///////////////////////////////////////////////////////////////////////////////////////////
			if (_dane->wejscie.CzyNajechany(_zapisyPrzycisk, _dane->okno))
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					_dane->maszyna.DodajStan(SR(new Zapisy(_dane)), true);
				}
				flaga2 = true;
			}
			else
			{
				flaga2 = false;
			}
			///////////////////////////////////////////////////////////////////////////////////////////
			if (_dane->wejscie.CzyNajechany(_wynikiPrzycisk, _dane->okno))
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					_dane->maszyna.DodajStan(SR(new Wyniki(_dane)), true);
				}
				flaga3 = true;
			}
			else
			{
				flaga3 = false;
			}
			//////////////////////////////////////////////////////////////////////////////////////////////
			if (_dane->wejscie.CzyNajechany(_wyjscie1, _dane->okno))
			{
				wyjscieZnacznik = true;
	
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					exit(0);
				}
			}
			else
				wyjscieZnacznik = false;
		}
	}

	void MenuGlowne::Rysuj(float delta)
	{
		_dane->okno.clear();

		_dane->okno.draw(_tlo);
		_dane->okno.draw(_tytul);

		if(flaga == false)
			_dane->okno.draw(_grajPrzycisk);
		else
			_dane->okno.draw(_grajPrzycisk2);

		if (flaga2 == false)
			_dane->okno.draw(_zapisyPrzycisk);
		else
			_dane->okno.draw(_zapisyPrzycisk2);

		if (flaga3 == false)
			_dane->okno.draw(_wynikiPrzycisk);
		else
			_dane->okno.draw(_wynikiPrzycisk2);

		if (wyjscieZnacznik == false)
			_dane->okno.draw(_wyjscie1);
		else
			_dane->okno.draw(_wyjscie2);

		_dane->okno.display();
	}
}