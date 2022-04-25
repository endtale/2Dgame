#include "StanWyniki.h"
#include "Definicje.h"
#include "G³ówneMenu.h"


namespace Moje
{
	Wyniki::Wyniki(DG dane) :_dane(dane)
	{
		flagaPowrotWyniki = false;
		wyjscieZnacznik = false;
		znacznikPodswietlenie1 = false;
		znacznikPodswietlenie2 = false;
		wybor = 1;
	}

	void Wyniki::Inicjalizacja()
	{
		_dane->aktyw.ladujTeksture("Zapisy Tlo", WYNIKI_TLO_LOKALIZACJA);
		_tlo.setTexture(this->_dane->aktyw.GetTexture("Zapisy Tlo"));

		_dane->aktyw.ladujTeksture("Powrot", POWROT_LOKALIZACJA);
		_powrot.setTexture(this->_dane->aktyw.GetTexture("Powrot"));
		_powrot.setPosition((SZER_OKNA)-(_powrot.getGlobalBounds().width * 1.15), (WYS_OKNA)-_powrot.getGlobalBounds().height * 1.15);

		_dane->aktyw.ladujTeksture("Powrot Nacisniety", POWROT_NACISNIETY_LOKALIZACJA);
		_powrotNacisniety.setTexture(this->_dane->aktyw.GetTexture("Powrot Nacisniety"));
		_powrotNacisniety.setPosition((SZER_OKNA)-(_powrotNacisniety.getGlobalBounds().width * 1.15), (WYS_OKNA)-_powrotNacisniety.getGlobalBounds().height * 1.15);

		_dane->aktyw.ladujTeksture("Wyjscie1", WYJSCIE_1_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Wyjscie2", WYJSCIE_2_LOKALIZACJA);
		_wyjscie1.setTexture(_dane->aktyw.GetTexture("Wyjscie1"));
		_wyjscie2.setTexture(_dane->aktyw.GetTexture("Wyjscie2"));
		_wyjscie1.setPosition(SZER_OKNA - _wyjscie1.getGlobalBounds().width, 0);
		_wyjscie2.setPosition(SZER_OKNA - _wyjscie1.getGlobalBounds().width, 0);

		_zmienLewo1.setTexture(this->_dane->aktyw.GetTexture("Powrot"));
		_zmienLewo1.setScale(0.2, 0.2);
		_zmienLewo1.setPosition(SZER_OKNA / 5, (WYS_OKNA / 6) + 20);

		_zmienLewo2.setTexture(this->_dane->aktyw.GetTexture("Powrot Nacisniety"));
		_zmienLewo2.setScale(0.2, 0.2);
		_zmienLewo2.setPosition(SZER_OKNA / 5, (WYS_OKNA / 6) + 20);

		_zmienPrawo1.setTexture(this->_dane->aktyw.GetTexture("Powrot"));
		_zmienPrawo1.setScale(-0.2, 0.2);
		_zmienPrawo1.setPosition(4 * (SZER_OKNA / 5), (WYS_OKNA / 6) + 20);

		_zmienPrawo2.setTexture(this->_dane->aktyw.GetTexture("Powrot Nacisniety"));
		_zmienPrawo2.setScale(-0.2, 0.2);
		_zmienPrawo2.setPosition(4 * (SZER_OKNA / 5), (WYS_OKNA / 6) + 20);

		_dane->aktyw.ladujCzcionke("Arial", CZCIONKA_LOKALIZACJA);
		_trudnosc.setFont(_dane->aktyw.GetFont("Arial"));
		_trudnosc.setCharacterSize(CZCIONKA_ROZMIAR * 1.8);
		_trudnosc.setFillColor(Color::Red);
		_trudnosc.setOutlineThickness(CZCIONKA_GRUBOSC);

		_usun.setFont(_dane->aktyw.GetFont("Arial"));
		_usun.setString(L"Usuñ wyniki !!!");
		_usun.setFillColor(Color::Red);
		_usun.setCharacterSize(CZCIONKA_ROZMIAR * 1.5);
		_usun.setOutlineThickness(CZCIONKA_GRUBOSC);
		_usun.setLetterSpacing(CZCIONKA_SPACING);
		_usun.setOrigin(_usun.getGlobalBounds().width / 2, 0);
		_usun.setPosition(200, WYS_OKNA - 65);

		for (int i = 0; i < 5; i++)
		{
			_wyniki[i].setFont(_dane->aktyw.GetFont("Arial"));
			_wyniki[i].setCharacterSize(CZCIONKA_ROZMIAR);
			_wyniki[i].setFillColor(Color::Black);
		}

		_dane->wejscie.odczyt("wynikiLatwy.dat", 5, _punktyLatwy);
		_dane->wejscie.odczyt("wynikiSredni.dat", 5, _punktySredni);
		_dane->wejscie.odczyt("wynikiTrudny.dat", 5, _punktyTrudny);
	}

	void Wyniki::OgarnijWejscie()
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

	void Wyniki::Aktualizuj(float delta)
	{
		if (wybor == 4)
			wybor = 1;
		if (wybor == 0)
			wybor = 3;

		if (_dane->wejscie.CzyNajechany(_usun, _dane->okno))
		{
			_usun.setFillColor(Color::Green);
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				switch (wybor)
				{
				case 1:
					_dane->wejscie.zapisUsun("wynikiLatwy.dat");
					break;
				case 2:
					_dane->wejscie.zapisUsun("wynikiSredni.dat");
					break;
				case 3:
					_dane->wejscie.zapisUsun("wynikiTrudny.dat");
					break;
				}

				_dane->wejscie.odczyt("wynikiLatwy.dat", 5, _punktyLatwy);
				_dane->wejscie.odczyt("wynikiSredni.dat", 5, _punktySredni);
				_dane->wejscie.odczyt("wynikiTrudny.dat", 5, _punktyTrudny);
			}
		}
		else
			_usun.setFillColor(Color::Red);

		if (wybor == 1)
		{
			_trudnosc.setString(L"£atwy");
			_trudnosc.setOrigin(_trudnosc.getGlobalBounds().width / 2, 0);
			_trudnosc.setPosition(SZER_OKNA / 2, (WYS_OKNA / 6));

			for (int i = 0; i < 5; i++)
			{
				String buf1 = to_string(i + 1);
				String buf2 = ". ";
				String buf3 = to_string(_punktyLatwy[i]);
				String buf4 = " p";
				_wyniki[i].setString(buf1 + buf2 + buf3 + buf4);
				if (i == 0)
				{
					_wyniki[i].setOrigin(_wyniki[0].getGlobalBounds().width / 2, 0);
					_wyniki[i].setPosition(SZER_OKNA / 2, (WYS_OKNA / 6) + 100 + i * 50);
				}
				else
					_wyniki[i].setPosition(_wyniki[0].getPosition().x - _wyniki[0].getGlobalBounds().width / 2, (WYS_OKNA / 6) + 100 + i * 50);
			}
		}
		if (wybor == 2)
		{
			_trudnosc.setString(L"Œredni");
			_trudnosc.setOrigin(_trudnosc.getGlobalBounds().width / 2, 0);
			_trudnosc.setPosition(SZER_OKNA / 2, (WYS_OKNA / 6));

			for (int i = 0; i < 5; i++)
			{
				String buf1 = to_string(i + 1);
				String buf2 = ". ";
				String buf3 = to_string(_punktySredni[i]);
				String buf4 = " p";
				_wyniki[i].setString(buf1 + buf2 + buf3 + buf4);
				if (i == 0)
				{
					_wyniki[i].setOrigin(_wyniki[0].getGlobalBounds().width / 2, 0);
					_wyniki[i].setPosition(SZER_OKNA / 2, (WYS_OKNA / 6) + 100 + i * 50);
				}
				else
					_wyniki[i].setPosition(_wyniki[0].getPosition().x - _wyniki[0].getGlobalBounds().width / 2, (WYS_OKNA / 6) + 100 + i * 50);
			}
		}
		if (wybor == 3)
		{
			_trudnosc.setString("Trudny");
			_trudnosc.setOrigin(_trudnosc.getGlobalBounds().width / 2, 0);
			_trudnosc.setPosition(SZER_OKNA / 2, (WYS_OKNA / 6));

			for (int i = 0; i < 5; i++)
			{
				String buf1 = to_string(i + 1);
				String buf2 = ". ";
				String buf3 = to_string(_punktyTrudny[i]);
				String buf4 = " p";
				_wyniki[i].setString(buf1 + buf2 + buf3 + buf4);
				if (i == 0)
				{
					_wyniki[i].setOrigin(_wyniki[0].getGlobalBounds().width / 2, 0);
					_wyniki[i].setPosition(SZER_OKNA / 2, (WYS_OKNA / 6) + 100 + i * 50);
				}
				else
					_wyniki[i].setPosition(_wyniki[0].getPosition().x - _wyniki[0].getGlobalBounds().width / 2, (WYS_OKNA / 6) + 100 + i * 50);
			}
		}

		if (_dane->wejscie.CzyNajechany(_zmienLewo1, _dane->okno) && zegar.getElapsedTime().asSeconds() > 0.15)
		{
			znacznikPodswietlenie1 = true;
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				zegar.restart();
				wybor--;
			}
		}
		else
			znacznikPodswietlenie1 = false;
		/////////////////////////////////////////////////////////
		if (_dane->wejscie.CzyNajechanyOdwrocony(_zmienPrawo1, _dane->okno) && zegar.getElapsedTime().asSeconds() > 0.15)
		{
			znacznikPodswietlenie2 = true;
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				zegar.restart();
				wybor++;
			}
		}
		else
			znacznikPodswietlenie2 = false;
		/////////////////////////////////////////////////////////
		if (_dane->wejscie.CzyNajechany(_powrot, _dane->okno))
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				_dane->maszyna.DodajStan(SR(new MenuGlowne(_dane)), true);
			}
			flagaPowrotWyniki = true;
		}
		else
			flagaPowrotWyniki = false;
		//////////////////////////////////////////////////////////////////////
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

	void Wyniki::Rysuj(float delta)
	{
		_dane->okno.clear();
		_dane->okno.draw(_tlo);

		_dane->okno.draw(_trudnosc);
		_dane->okno.draw(_usun);

		for (int i = 0; i < 5; i++)
			_dane->okno.draw(_wyniki[i]);

		if (flagaPowrotWyniki == false)
			_dane->okno.draw(_powrot);
		if (flagaPowrotWyniki == true)
			_dane->okno.draw(_powrotNacisniety);

		if (wyjscieZnacznik == false)
			_dane->okno.draw(_wyjscie1);
		else
			_dane->okno.draw(_wyjscie2);

		if (znacznikPodswietlenie1 == false)
			_dane->okno.draw(_zmienLewo1);
		else
			_dane->okno.draw(_zmienLewo2);

		if (znacznikPodswietlenie2 == false)
			_dane->okno.draw(_zmienPrawo1);
		else
			_dane->okno.draw(_zmienPrawo2);

		_dane->okno.display();
	}
}

