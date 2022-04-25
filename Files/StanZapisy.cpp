#include "StanZapisy.h"
#include "Definicje.h"
#include "G³ówneMenu.h"


namespace Moje
{
	Zapisy::Zapisy(DG dane) :_dane(dane)
	{
		flagaPowrotZapisy = false;
		wyjscieZnacznik = false;
		zapisIstnieje = true;
	}

	void Zapisy::Inicjalizacja()
	{
		_dane->aktyw.ladujTeksture("Zapisy Tlo", ZAPISY_TLO_LOKALIZACJA);
		_tlo.setTexture(this->_dane->aktyw.GetTexture("Zapisy Tlo"));

		_dane->aktyw.ladujTeksture("Powrot", POWROT_LOKALIZACJA);
		_powrot.setTexture(this->_dane->aktyw.GetTexture("Powrot"));
		_powrot.setPosition((SZER_OKNA) - (_powrot.getGlobalBounds().width *1.15), (WYS_OKNA) - _powrot.getGlobalBounds().height *1.15);

		_dane->aktyw.ladujTeksture("Powrot Nacisniety", POWROT_NACISNIETY_LOKALIZACJA);
		_powrotNacisniety.setTexture(this->_dane->aktyw.GetTexture("Powrot Nacisniety"));
		_powrotNacisniety.setPosition((SZER_OKNA) - (_powrotNacisniety.getGlobalBounds().width * 1.15), (WYS_OKNA) - _powrotNacisniety.getGlobalBounds().height * 1.15);

		_dane->aktyw.ladujTeksture("Wyjscie1", WYJSCIE_1_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Wyjscie2", WYJSCIE_2_LOKALIZACJA);
		_wyjscie1.setTexture(_dane->aktyw.GetTexture("Wyjscie1"));
		_wyjscie2.setTexture(_dane->aktyw.GetTexture("Wyjscie2"));
		_wyjscie1.setPosition(SZER_OKNA - _wyjscie1.getGlobalBounds().width, 0);
		_wyjscie2.setPosition(SZER_OKNA - _wyjscie1.getGlobalBounds().width, 0);

		_dane->aktyw.ladujCzcionke("Arial", CZCIONKA_LOKALIZACJA);

		_logo.setFont(_dane->aktyw.GetFont("Arial"));
		_logo.setString(L"Wybierz Poziom Trudnoœci");
		_logo.setCharacterSize(CZCIONKA_ROZMIAR * 1.8);
		_logo.setFillColor(Color::Red);
		_logo.setOutlineThickness(CZCIONKA_GRUBOSC);
		_logo.setLetterSpacing(CZCIONKA_SPACING);
		_logo.setOrigin(_logo.getGlobalBounds().width / 2, 0);
		_logo.setPosition(SZER_OKNA / 2, (WYS_OKNA / 4) );

		_zapis1.setFont(_dane->aktyw.GetFont("Arial"));
		_zapis1.setString("Zapis1");
		_zapis1.setFillColor(Color::Red);
		_zapis1.setCharacterSize(CZCIONKA_ROZMIAR * 1.5);
		_zapis1.setOutlineThickness(CZCIONKA_GRUBOSC);
		_zapis1.setLetterSpacing(CZCIONKA_SPACING);
		_zapis1.setOrigin(_zapis1.getGlobalBounds().width / 2, 0);
		_zapis1.setPosition(SZER_OKNA / 5, 1.5 * (WYS_OKNA / 3));

		_zapis2.setFont(_dane->aktyw.GetFont("Arial"));
		_zapis2.setString("Zapis2");
		_zapis2.setFillColor(Color::Red);
		_zapis2.setCharacterSize(CZCIONKA_ROZMIAR * 1.5);
		_zapis2.setOutlineThickness(CZCIONKA_GRUBOSC);
		_zapis2.setLetterSpacing(CZCIONKA_SPACING);
		_zapis2.setOrigin(_zapis2.getGlobalBounds().width / 2, 0);
		_zapis2.setPosition(SZER_OKNA / 2, 1.5 * (WYS_OKNA / 3));

		_zapis3.setFont(_dane->aktyw.GetFont("Arial"));
		_zapis3.setString("Zapis3");
		_zapis3.setFillColor(Color::Red);
		_zapis3.setCharacterSize(CZCIONKA_ROZMIAR * 1.5);
		_zapis3.setOutlineThickness(CZCIONKA_GRUBOSC);
		_zapis3.setLetterSpacing(CZCIONKA_SPACING);
		_zapis3.setOrigin(_zapis3.getGlobalBounds().width / 2, 0);
		_zapis3.setPosition(4 * (SZER_OKNA / 5), 1.5 * (WYS_OKNA / 3));

		_usun.setFont(_dane->aktyw.GetFont("Arial"));
		_usun.setString(L"Usuñ zapisy!!!");
		_usun.setFillColor(Color::Red);
		_usun.setCharacterSize(CZCIONKA_ROZMIAR * 1.5);
		_usun.setOutlineThickness(CZCIONKA_GRUBOSC);
		_usun.setLetterSpacing(CZCIONKA_SPACING);
		_usun.setOrigin(_usun.getGlobalBounds().width / 2, 0);
		_usun.setPosition(SZER_OKNA / 2, 1.5 * (WYS_OKNA / 3) + 100);

		_nieIstnieje.setFont(_dane->aktyw.GetFont("Arial"));
		_nieIstnieje.setString("Zapis nie istnieje!!!");
		_nieIstnieje.setFillColor(Color::Black);
		_nieIstnieje.setCharacterSize(CZCIONKA_ROZMIAR * 2);
		_nieIstnieje.setPosition(100, WYS_OKNA - 100);
	}

	void Zapisy::OgarnijWejscie()
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

	void  Zapisy::poziom(int i)
	{
		if (i == 1)
			_dane->wejscie.poziomSet(Latwy);
		if (i == 2)
			_dane->wejscie.poziomSet(Sredni);
		if (i == 3)
			_dane->wejscie.poziomSet(Trudny);
	}

	void Zapisy::Aktualizuj(float delta)
	{
		if (zegar2.getElapsedTime().asSeconds() > 1)
			zapisIstnieje = true;

		if (zegar.getElapsedTime().asSeconds() > 0.15)
		{
			if (_dane->wejscie.CzyNajechany(_powrot, _dane->okno))
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					_dane->maszyna.DodajStan(SR(new MenuGlowne(_dane)), true);
				}
				flagaPowrotZapisy = true;
			}
			else
				flagaPowrotZapisy = false;


			if (_dane->wejscie.CzyNajechany(_usun, _dane->okno))
			{
				_usun.setFillColor(Color::Green);
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					_dane->wejscie.zapisUsun("Zapis1.dat");
					_dane->wejscie.zapisUsun("Zapis2.dat");
					_dane->wejscie.zapisUsun("Zapis3.dat");
				}
			}
			else
				_usun.setFillColor(Color::Red);

			if (_dane->wejscie.CzyNajechany(_zapis1, _dane->okno))
			{
				_zapis1.setFillColor(Color::Green);
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					_dane->wejscie.odczyt("Zapis1.dat", 5, buf);
					if (buf[0] == 0)
					{
						zapisIstnieje = false;
						zegar2.restart();
					}
					else
					{
						_dane->wejscie.punktySet(buf[1]);
						_dane->wejscie.znacznikPunktySet(buf[2]);
						_dane->wejscie.hpSet(buf[3]);
						poziom(buf[4]);
						_dane->maszyna.DodajStan(SR(new StanGry(_dane)), true);
					}
				}
			}
			else
				_zapis1.setFillColor(Color::Red);

			if (_dane->wejscie.CzyNajechany(_zapis2, _dane->okno))
			{
				_zapis2.setFillColor(Color::Green);
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					_dane->wejscie.odczyt("Zapis2.dat", 5, buf);
					if (buf[0] == 0)
					{
						zapisIstnieje = false;
						zegar2.restart();
					}
					else
					{
						_dane->wejscie.punktySet(buf[1]);
						_dane->wejscie.znacznikPunktySet(buf[2]);
						_dane->wejscie.hpSet(buf[3]);
						poziom(buf[4]);
						_dane->maszyna.DodajStan(SR(new StanGry(_dane)), true);
					}
				}
			}
			else
				_zapis2.setFillColor(Color::Red);

			if (_dane->wejscie.CzyNajechany(_zapis3, _dane->okno))
			{
				_zapis3.setFillColor(Color::Green);
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					_dane->wejscie.odczyt("Zapis3.dat", 5, buf);
					if (buf[0] == 0)
					{
						zapisIstnieje = false;
						zegar2.restart();
					}
					else
					{
						_dane->wejscie.punktySet(buf[1]);
						_dane->wejscie.znacznikPunktySet(buf[2]);
						_dane->wejscie.hpSet(buf[3]);
						poziom(buf[4]);
						_dane->maszyna.DodajStan(SR(new StanGry(_dane)), true);
					}
				}
			}
			else
				_zapis3.setFillColor(Color::Red);

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

	void Zapisy::Rysuj(float delta)
	{
		_dane->okno.clear();
		_dane->okno.draw(_tlo);
		_dane->okno.draw(_zapis1);
		_dane->okno.draw(_zapis2);
		_dane->okno.draw(_zapis3);
		_dane->okno.draw(_logo);
		_dane->okno.draw(_usun);

		if (zapisIstnieje == false)
			_dane->okno.draw(_nieIstnieje);

		if (flagaPowrotZapisy == false)
			_dane->okno.draw(_powrot);
		else
			_dane->okno.draw(_powrotNacisniety);

		if (wyjscieZnacznik == false)
			_dane->okno.draw(_wyjscie1);
		else
			_dane->okno.draw(_wyjscie2);
		
		_dane->okno.display();
	}
}

