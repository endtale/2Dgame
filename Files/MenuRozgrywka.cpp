#include "MenuRozgrywka.h"

namespace Moje
{
	MenuRozgrywka::MenuRozgrywka(DG dane) : _dane(dane)
	{
		wybor = 1;
		akcja = false;
		zapisMozliwy = false;
		zapisZnacznik = 0;

		_tlo.setTexture(_dane->aktyw.GetTexture("MenuTlo"));
		_okno.setTexture(_dane->aktyw.GetTexture("Okno"));

		_wznow.setFont(_dane->aktyw.GetFont("Arial"));
		_wznow.setString(L"Wznów");
		_wznow.setCharacterSize(CZCIONKA_ROZMIAR * 1.5);
		_wznow.setOutlineThickness(CZCIONKA_GRUBOSC);
		_wznow.setOrigin(_wznow.getGlobalBounds().width / 2, 0);
		_wznow.setPosition(SZER_OKNA / 2, 1.2 * (WYS_OKNA / 5) );

		_zapisz.setFont(_dane->aktyw.GetFont("Arial"));
		_zapisz.setString("Zapisz");
		_zapisz.setCharacterSize(CZCIONKA_ROZMIAR * 1.5);
		_zapisz.setOutlineThickness(CZCIONKA_GRUBOSC);
		_zapisz.setOrigin(_zapisz.getGlobalBounds().width / 2, 0);
		_zapisz.setPosition(SZER_OKNA / 2, 1.8 * (WYS_OKNA / 5));

		_domenu.setFont(_dane->aktyw.GetFont("Arial"));
		_domenu.setString("Do menu");
		_domenu.setCharacterSize(CZCIONKA_ROZMIAR * 1.5);
		_domenu.setOutlineThickness(CZCIONKA_GRUBOSC);
		_domenu.setOrigin(_domenu.getGlobalBounds().width / 2, 0);
		_domenu.setPosition(SZER_OKNA / 2, 2.5 * (WYS_OKNA / 5));

		_wyjscie.setFont(_dane->aktyw.GetFont("Arial"));
		_wyjscie.setString("Do pulpitu");
		_wyjscie.setCharacterSize(CZCIONKA_ROZMIAR * 1.5);
		_wyjscie.setOutlineThickness(CZCIONKA_GRUBOSC);
		_wyjscie.setOrigin(_wyjscie.getGlobalBounds().width / 2, 0);
		_wyjscie.setPosition(SZER_OKNA / 2, 3.2 * (WYS_OKNA / 5));

		_zapis.setFont(_dane->aktyw.GetFont("Arial"));
		_zapis.setFillColor(Color::Black);
		_zapis.setCharacterSize(CZCIONKA_ROZMIAR);
		
		_zapis1.setFont(_dane->aktyw.GetFont("Arial"));
		_zapis1.setString("Slot1");
		_zapis1.setCharacterSize(CZCIONKA_ROZMIAR);
		_zapis1.setOrigin(_zapis1.getGlobalBounds().width / 2, 0);
		_zapis1.setPosition((SZER_OKNA / 2) - 80, (WYS_OKNA / 2) - 20);

		_zapis2.setFont(_dane->aktyw.GetFont("Arial"));
		_zapis2.setString("Slot2");
		_zapis2.setCharacterSize(CZCIONKA_ROZMIAR);
		_zapis2.setOrigin(_zapis2.getGlobalBounds().width / 2, 0);
		_zapis2.setPosition((SZER_OKNA / 2), (WYS_OKNA / 2) - 20);

		_zapis3.setFont(_dane->aktyw.GetFont("Arial"));
		_zapis3.setString("Slot3");
		_zapis3.setCharacterSize(CZCIONKA_ROZMIAR);
		_zapis3.setOrigin(_zapis3.getGlobalBounds().width / 2, 0);
		_zapis3.setPosition((SZER_OKNA / 2) + 80, (WYS_OKNA / 2) - 20);

		_wyjscieOkno.setFont(_dane->aktyw.GetFont("Arial"));
		_wyjscieOkno.setString(L"Wyjœcie");
		_wyjscieOkno.setCharacterSize(CZCIONKA_ROZMIAR);
		_wyjscieOkno.setOutlineThickness(CZCIONKA_GRUBOSC);
		_wyjscieOkno.setOrigin(_wyjscieOkno.getGlobalBounds().width / 2, 0);
		_wyjscieOkno.setPosition((SZER_OKNA / 2), (WYS_OKNA / 2) + 20);

		_rozumiem.setFont(_dane->aktyw.GetFont("Arial"));
		_rozumiem.setString("Rozumiem");
		_rozumiem.setCharacterSize(CZCIONKA_ROZMIAR);
		_rozumiem.setOutlineThickness(CZCIONKA_GRUBOSC);
		_rozumiem.setOrigin(_rozumiem.getGlobalBounds().width / 2, 0);
		_rozumiem.setPosition((SZER_OKNA / 2), (WYS_OKNA / 2) + 40);
	}

	void MenuRozgrywka::aktualizuj()
	{
		if (akcja == false)
		{
			if (Keyboard::isKeyPressed(Keyboard::Down) && zegar.getElapsedTime().asSeconds() > 0.15)
			{
				wybor++;
				if (wybor == 5)
					wybor = 1;
				zegar.restart();
			}
			if (Keyboard::isKeyPressed(Keyboard::Up) && zegar.getElapsedTime().asSeconds() > 0.15)
			{
				wybor--;
				if (wybor == 0)
					wybor = 4;
				zegar.restart();
			}
		}

		switch (wybor)
		{
		case 1:
			_wznow.setFillColor(Color::Green);
			_zapisz.setFillColor(Color::Red);
			_domenu.setFillColor(Color::Red);
			_wyjscie.setFillColor(Color::Red);

			break;
		case 2:
			_wznow.setFillColor(Color::Red);
			_zapisz.setFillColor(Color::Green);
			_domenu.setFillColor(Color::Red);
			_wyjscie.setFillColor(Color::Red);

			if (akcja == true)
			{
				if (zapisMozliwy == false)
				{
					_zapis.setString(L"Nie mozesz zapisaæ gry!!!\n\t SprawdŸ pomoc!!!");
					_zapis.setOrigin(_zapis.getGlobalBounds().width / 2, 0);
					_zapis.setPosition((SZER_OKNA / 2), (WYS_OKNA / 2) - 60);

					if (_dane->wejscie.CzyNajechany(_rozumiem, _dane->okno))
					{
						_rozumiem.setFillColor(Color:: Green);
						if (Mouse::isButtonPressed(Mouse::Left))
							akcja = false;
					}
					else
						_rozumiem.setFillColor(Color::Red);
				}
				else if (zapisMozliwy == true && zapisZnacznik == 0)
				{
					_zapis.setString("Wybierz slot zapisu");
					_zapis.setOrigin(_zapis.getGlobalBounds().width / 2, 0);
					_zapis.setPosition((SZER_OKNA / 2), (WYS_OKNA / 2) - 60);

					if (_dane->wejscie.CzyNajechany(_wyjscieOkno, _dane->okno))
					{
						_wyjscieOkno.setFillColor(Color::Green);
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							zapisZnacznik = 0;
							akcja = false;
						}
					}
					else
						_wyjscieOkno.setFillColor(Color::Red);

					if (_dane->wejscie.CzyNajechany(_zapis1, _dane->okno))
					{
						_zapis1.setFillColor(Color::Green);
						if (Mouse::isButtonPressed(Mouse::Left))
						zapisZnacznik = 1;
					}
					else
						_zapis1.setFillColor(Color::Red);

					if (_dane->wejscie.CzyNajechany(_zapis2, _dane->okno))
					{
						_zapis2.setFillColor(Color::Green);
						if (Mouse::isButtonPressed(Mouse::Left))
							zapisZnacznik = 2;
					}
					else
						_zapis2.setFillColor(Color::Red);

					if (_dane->wejscie.CzyNajechany(_zapis3, _dane->okno))
					{
						_zapis3.setFillColor(Color::Green);
						if (Mouse::isButtonPressed(Mouse::Left))
							zapisZnacznik = 3;
					}
					else
						_zapis3.setFillColor(Color::Red);
				}
				else if (zapisMozliwy == true && zapisZnacznik > 0)
				{
					_zapis.setString(L"Zapisano pomyœlnie!!!");
					_zapis.setOrigin(_zapis.getGlobalBounds().width / 2, 0);
					_zapis.setPosition((SZER_OKNA / 2), (WYS_OKNA / 2) - 60);

					if (_dane->wejscie.CzyNajechany(_wyjscieOkno, _dane->okno))
					{
						_wyjscieOkno.setFillColor(Color::Green);
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							zapisZnacznik = 0;
							akcja = false;
						}
					}
					else
						_wyjscieOkno.setFillColor(Color::Red);
				}
			}
			break;
		case 3:
			_wznow.setFillColor(Color::Red);
			_zapisz.setFillColor(Color::Red);
			_domenu.setFillColor(Color::Green);
			_wyjscie.setFillColor(Color::Red);
			break;
		case 4:
			_wznow.setFillColor(Color::Red);
			_zapisz.setFillColor(Color::Red);
			_domenu.setFillColor(Color::Red);
			_wyjscie.setFillColor(Color::Green);
		}
	}

	void MenuRozgrywka::rysujMenu()
	{
		_dane->okno.draw(_tlo);
		_dane->okno.draw(_wznow);
		_dane->okno.draw(_zapisz);
		_dane->okno.draw(_domenu);
		_dane->okno.draw(_wyjscie);

		if (akcja == true)
		{
			_dane->okno.draw(_okno);
			_dane->okno.draw(_zapis);
			if (zapisMozliwy == false)
				_dane->okno.draw(_rozumiem);
			else
			{
				if (zapisZnacznik == 0)
				{
					_dane->okno.draw(_zapis1);
					_dane->okno.draw(_zapis2);
					_dane->okno.draw(_zapis3);
				}
				_dane->okno.draw(_wyjscieOkno);
			}
		}
	}

	unsigned short int MenuRozgrywka::wyborGet()
	{
		return wybor;
	}
	unsigned short int MenuRozgrywka::zapisZnacznikGet()
	{
		return zapisZnacznik;
	}
	void MenuRozgrywka::akcjaSet(bool akcja)
	{
		this->akcja = akcja;
	}
	void MenuRozgrywka::zapisSet(bool zapis)
	{
		zapisMozliwy = zapis;
	}
}
