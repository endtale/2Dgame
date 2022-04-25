#include "StanPrzegrana.h"
#include "Definicje.h"
#include "G³ówneMenu.h"

namespace Moje
{
	Przegrana::Przegrana(DG dane) :_dane(dane)
	{
		wyjscieZnacznik = false;
	}

	void Przegrana::Inicjalizacja()
	{
		_dane->aktyw.ladujTeksture("Gra Tlo", KONIECGRY_TLO_LOKALIZACJA);
		_tlo.setTexture(this->_dane->aktyw.GetTexture("Gra Tlo"));

		_dane->aktyw.ladujTeksture("Gameover", GAMEOVER_LOKALIZACJA);
		_gameover.setTexture(this->_dane->aktyw.GetTexture("Gameover"));
		_gameover.setScale(0.5, 0.5);
		_gameover.setPosition((SZER_OKNA / 2) - (_gameover.getGlobalBounds().width / 2), (WYS_OKNA / 3) - _gameover.getGlobalBounds().height/1.4);

		_dane->aktyw.ladujTeksture("Powrot", POWROT_LOKALIZACJA);
		_powrot.setTexture(this->_dane->aktyw.GetTexture("Powrot"));
		_powrot.setPosition((SZER_OKNA /2 )-(_powrot.getGlobalBounds().width / 2), (WYS_OKNA) - (WYS_OKNA / 4) - _powrot.getGlobalBounds().height / 2);

		_dane->aktyw.ladujTeksture("Powrot Nacisniety", POWROT_NACISNIETY_LOKALIZACJA);
		_powrotNacisniety.setTexture(this->_dane->aktyw.GetTexture("Powrot Nacisniety"));
		_powrotNacisniety.setPosition((SZER_OKNA / 2) - (_powrotNacisniety.getGlobalBounds().width / 2), (WYS_OKNA)-(WYS_OKNA / 4) - _powrotNacisniety.getGlobalBounds().height / 2);

		_dane->aktyw.ladujCzcionke("Arial", CZCIONKA_LOKALIZACJA);

		punkty = _dane->wejscie.punktyGet();
		String S1 = "Zdobyte Punkty: ";
		String S2 = to_string(punkty);
		_punkty.setFont(_dane->aktyw.GetFont("Arial"));
		_punkty.setString(S1 + S2);
		_punkty.setCharacterSize(CZCIONKA_ROZMIAR * 1.8);
		_punkty.setFillColor(Color::Red);
		_punkty.setOutlineThickness(CZCIONKA_GRUBOSC);
		_punkty.setLetterSpacing(CZCIONKA_SPACING);
		_punkty.setOrigin(_punkty.getGlobalBounds().width / 2, 0);
		_punkty.setPosition(SZER_OKNA / 2, (WYS_OKNA / 2) - _punkty.getGlobalBounds().height);

		_dane->aktyw.ladujTeksture("Wyjscie1", WYJSCIE_1_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Wyjscie2", WYJSCIE_2_LOKALIZACJA);
		_wyjscie1.setTexture(_dane->aktyw.GetTexture("Wyjscie1"));
		_wyjscie2.setTexture(_dane->aktyw.GetTexture("Wyjscie2"));
		_wyjscie1.setPosition(SZER_OKNA - _wyjscie1.getGlobalBounds().width, 0);
		_wyjscie2.setPosition(SZER_OKNA - _wyjscie1.getGlobalBounds().width, 0);
	}

	bool  flagaPowrotGameover = false;

	void Przegrana::OgarnijWejscie()
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

	void Przegrana::Aktualizuj(float delta)
	{
		if (_dane->wejscie.CzyNajechany(_powrot, _dane->okno))
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				_dane->maszyna.DodajStan(SR(new MenuGlowne(_dane)), true);
			}
			flagaPowrotGameover = true;
		}
		else
		{
			flagaPowrotGameover = false;
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

	void Przegrana::Rysuj(float delta)
	{
		_dane->okno.clear();
		_dane->okno.draw(_tlo);
		_dane->okno.draw(_gameover);
		_dane->okno.draw(_punkty);

		if (flagaPowrotGameover == false)
			_dane->okno.draw(_powrot);
		if (flagaPowrotGameover == true)
			_dane->okno.draw(_powrotNacisniety);

		if (wyjscieZnacznik == false)
			_dane->okno.draw(_wyjscie1);
		else
			_dane->okno.draw(_wyjscie2);

		_dane->okno.display();
	}
}

