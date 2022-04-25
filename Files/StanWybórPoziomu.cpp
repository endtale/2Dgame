#include "StanWybórPoziomu.h"

namespace Moje
{
	Poziom::Poziom(DG dane) : _dane(dane)
	{
		wyjscieZnacznik = false;
	}

	void Poziom::Inicjalizacja()
	{
		_dane->aktyw.ladujTeksture("Tlo", GRA_TLO_LOKALIZACJA);
		_tlo.setTexture(this->_dane->aktyw.GetTexture("Tlo"));

		_dane->aktyw.ladujTeksture("Menu Tytul", MENU_TYTUL_LOKALIZACJA);
		_tytul.setTexture(this->_dane->aktyw.GetTexture("Menu Tytul"));
		_tytul.setPosition((SZER_OKNA / 2) - (_tytul.getGlobalBounds().width / 2), _tytul.getGlobalBounds().height / 10);

		_dane->aktyw.ladujTeksture("Powrot", POWROT_LOKALIZACJA);
		_powrot.setTexture(this->_dane->aktyw.GetTexture("Powrot"));
		_powrot.setPosition((SZER_OKNA)-(_powrot.getGlobalBounds().width * 1.15), (WYS_OKNA)-_powrot.getGlobalBounds().height * 1.15);

		_dane->aktyw.ladujTeksture("Powrot Nacisniety", POWROT_NACISNIETY_LOKALIZACJA);
		_powrotNacisniety.setTexture(this->_dane->aktyw.GetTexture("Powrot Nacisniety"));
		_powrotNacisniety.setPosition((SZER_OKNA)-(_powrotNacisniety.getGlobalBounds().width * 1.15), (WYS_OKNA)-_powrotNacisniety.getGlobalBounds().height * 1.15);

		_dane->aktyw.ladujCzcionke("Arial", CZCIONKA_LOKALIZACJA);

		_czcionkaNapis.setFont(_dane->aktyw.GetFont("Arial"));
		_czcionkaNapis.setString(L"Wybierz Poziom Trudnoœci");
		_czcionkaNapis.setCharacterSize(CZCIONKA_ROZMIAR * 1.8);
		_czcionkaNapis.setFillColor(Color::Red);
		_czcionkaNapis.setOutlineThickness(CZCIONKA_GRUBOSC);
		_czcionkaNapis.setLetterSpacing(CZCIONKA_SPACING);
		_czcionkaNapis.setOrigin(_czcionkaNapis.getGlobalBounds().width / 2, 0);
		_czcionkaNapis.setPosition(SZER_OKNA / 2, (WYS_OKNA / 3) + 30);

		_czcionkaLatwy.setFont(_dane->aktyw.GetFont("Arial"));
		_czcionkaLatwy.setString(L"£atwy");
		_czcionkaLatwy.setCharacterSize(CZCIONKA_ROZMIAR * 1.5);
		_czcionkaLatwy.setFillColor(Color::Red);
		_czcionkaLatwy.setOutlineThickness(CZCIONKA_GRUBOSC);
		_czcionkaLatwy.setLetterSpacing(CZCIONKA_SPACING);
		_czcionkaLatwy.setOrigin(_czcionkaLatwy.getGlobalBounds().width / 2, 0);
		_czcionkaLatwy.setPosition(SZER_OKNA / 5, (WYS_OKNA / 3) + 130);

		_czcionkaSredni.setFont(_dane->aktyw.GetFont("Arial"));
		_czcionkaSredni.setString(L"Œredni");
		_czcionkaSredni.setCharacterSize(CZCIONKA_ROZMIAR * 1.5);
		_czcionkaSredni.setFillColor(Color::Red);
		_czcionkaSredni.setOutlineThickness(CZCIONKA_GRUBOSC);
		_czcionkaSredni.setLetterSpacing(CZCIONKA_SPACING);
		_czcionkaSredni.setOrigin(_czcionkaSredni.getGlobalBounds().width / 2, 0);
		_czcionkaSredni.setPosition(SZER_OKNA / 2, (WYS_OKNA / 3) + 130);

		_czcionkaTrudny.setFont(_dane->aktyw.GetFont("Arial"));
		_czcionkaTrudny.setString("Trudny");
		_czcionkaTrudny.setCharacterSize(CZCIONKA_ROZMIAR * 1.5);
		_czcionkaTrudny.setFillColor(Color::Red);
		_czcionkaTrudny.setOutlineThickness(CZCIONKA_GRUBOSC);
		_czcionkaTrudny.setLetterSpacing(CZCIONKA_SPACING);
		_czcionkaTrudny.setOrigin(_czcionkaTrudny.getGlobalBounds().width / 2, 0);
		_czcionkaTrudny.setPosition(4 * (SZER_OKNA / 5), (WYS_OKNA / 3) + 130);

		_dane->aktyw.ladujTeksture("Wyjscie1", WYJSCIE_1_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Wyjscie2", WYJSCIE_2_LOKALIZACJA);
		_wyjscie1.setTexture(_dane->aktyw.GetTexture("Wyjscie1"));
		_wyjscie2.setTexture(_dane->aktyw.GetTexture("Wyjscie2"));
		_wyjscie1.setPosition(SZER_OKNA - _wyjscie1.getGlobalBounds().width, 0);
		_wyjscie2.setPosition(SZER_OKNA - _wyjscie1.getGlobalBounds().width, 0);
	}

	void Poziom::OgarnijWejscie()
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

	void Poziom::Aktualizuj(float delta)
	{
		if(zegar.getElapsedTime().asSeconds() > 0.15)
		{
			if (_dane->wejscie.CzyNajechany(_powrot, _dane->okno))
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					_dane->maszyna.DodajStan(SR(new MenuGlowne(_dane)), true);
				}
				flagaPowrot = true;
			}
			else 
			{
				flagaPowrot = false;
			}

			if (_dane->wejscie.CzyNajechany(_czcionkaLatwy, _dane->okno))
			{
				_czcionkaLatwy.setFillColor(Color::Green);
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					_dane->wejscie.poziomSet(Latwy);
					_dane->wejscie.punktySet(0);
					_dane->wejscie.znacznikPunktySet(0);
					_dane->wejscie.hpSet(10);
					_dane->maszyna.DodajStan(SR(new StanGry(_dane)), true);
				}
			}
			else 
			{
				_czcionkaLatwy.setFillColor(Color::Red);
			}

			if (_dane->wejscie.CzyNajechany(_czcionkaSredni, _dane->okno))
			{
				_czcionkaSredni.setFillColor(Color::Green);
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					_dane->wejscie.poziomSet(Sredni);
					_dane->wejscie.punktySet(0);
					_dane->wejscie.znacznikPunktySet(0);
					_dane->wejscie.hpSet(6);
					_dane->maszyna.DodajStan(SR(new StanGry(_dane)), true);
				}
			}
			else 
			{
				_czcionkaSredni.setFillColor(Color::Red);
			}

			if (_dane->wejscie.CzyNajechany(_czcionkaTrudny, _dane->okno))
			{
				_czcionkaTrudny.setFillColor(Color::Green);
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					_dane->wejscie.poziomSet(Trudny);
					_dane->wejscie.punktySet(0);
					_dane->wejscie.znacznikPunktySet(0);
					_dane->wejscie.hpSet(4);
					_dane->maszyna.DodajStan(SR(new StanGry(_dane)), true);
				}
			}
			else 
			{
				_czcionkaTrudny.setFillColor(Color::Red);
			}

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

	void Poziom::Rysuj(float delta)
	{
		_dane->okno.clear();

		_dane->okno.draw(_tlo);
		_dane->okno.draw(_tytul);
		if (flagaPowrot == false)
			_dane->okno.draw(_powrot);
		if (flagaPowrot == true)
			_dane->okno.draw(_powrotNacisniety);

		if (wyjscieZnacznik == false)
			_dane->okno.draw(_wyjscie1);
		else
			_dane->okno.draw(_wyjscie2);

		_dane->okno.draw(_czcionkaNapis);
		_dane->okno.draw(_czcionkaLatwy);
		_dane->okno.draw(_czcionkaSredni);
		_dane->okno.draw(_czcionkaTrudny);

		_dane->okno.display();
	}
}