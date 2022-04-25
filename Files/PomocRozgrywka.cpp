#include "PomocRozgrywka.h"

namespace Moje
{
	PomocRozgrywka::PomocRozgrywka(DG dane) : _dane(dane)
	{
		wybor = 1;
		znacznikPodswietlenie1 = false;
		znacznikPodswietlenie2 = false;
		wyjscieZnacznik = false;
		_wyjscie = false;

		_tlo.setTexture(_dane->aktyw.GetTexture("MenuTlo"));
		_ster.setTexture(_dane->aktyw.GetTexture("Sterowanie"));
		_punktacja.setTexture(_dane->aktyw.GetTexture("Punktacja"));
		_zapisy.setTexture(_dane->aktyw.GetTexture("Zapisy"));

		_wyjscie1.setTexture(_dane->aktyw.GetTexture("Wyjscie1"));
		_wyjscie2.setTexture(_dane->aktyw.GetTexture("Wyjscie2"));
		_wyjscie1.setPosition(4 * (SZER_OKNA / 5) - _wyjscie1.getGlobalBounds().width + 6, (WYS_OKNA / 6));
		_wyjscie2.setPosition(4 * (SZER_OKNA / 5) - _wyjscie1.getGlobalBounds().width + 6, (WYS_OKNA / 6));

		_zmienLewo1.setTexture(this->_dane->aktyw.GetTexture("Powrot"));
		_zmienLewo1.setScale(0.2, 0.2);
		_zmienLewo1.setPosition(SZER_OKNA / 5, (WYS_OKNA / 4) + 20);

		_zmienLewo2.setTexture(this->_dane->aktyw.GetTexture("Powrot Nacisniety"));
		_zmienLewo2.setScale(0.2, 0.2);
		_zmienLewo2.setPosition(SZER_OKNA / 5, (WYS_OKNA / 4) + 20);

		_zmienPrawo1.setTexture(this->_dane->aktyw.GetTexture("Powrot"));
		_zmienPrawo1.setScale(-0.2, 0.2);
		_zmienPrawo1.setPosition(4 * (SZER_OKNA / 5), (WYS_OKNA / 4) + 20);

		_zmienPrawo2.setTexture(this->_dane->aktyw.GetTexture("Powrot Nacisniety"));
		_zmienPrawo2.setScale(-0.2, 0.2);
		_zmienPrawo2.setPosition(4 * (SZER_OKNA / 5), (WYS_OKNA / 4) + 20);

		_sterowanie.setFont(_dane->aktyw.GetFont("Arial"));
		_sterowanie.setCharacterSize(CZCIONKA_ROZMIAR * 1.8);
		_sterowanie.setFillColor(Color::Red);
		_sterowanie.setOutlineThickness(CZCIONKA_GRUBOSC);
	}

	void PomocRozgrywka::aktualizuj()
	{
		if (wybor == 4)
			wybor = 1;
		if (wybor == 0)
			wybor = 3;

		if (wybor == 1)
		{
			_sterowanie.setString("Sterowanie");
			_sterowanie.setOrigin(_sterowanie.getGlobalBounds().width / 2, 0);
			_sterowanie.setPosition(SZER_OKNA / 2, (WYS_OKNA / 4));
		}
		if (wybor == 2)
		{
			_sterowanie.setString("Punkty");
			_sterowanie.setOrigin(_sterowanie.getGlobalBounds().width / 2, 0);
			_sterowanie.setPosition(SZER_OKNA / 2, (WYS_OKNA / 4));
		}
		if (wybor == 3)
		{
			_sterowanie.setString("Zapis");
			_sterowanie.setOrigin(_sterowanie.getGlobalBounds().width / 2, 0);
			_sterowanie.setPosition(SZER_OKNA / 2, (WYS_OKNA / 4));
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
		///////////////////////////////////////////////////////////
		if (_dane->wejscie.CzyNajechany(_wyjscie1, _dane->okno))
		{
			wyjscieZnacznik = true;
			_wyjscie = false;
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				_wyjscie = true;
			}
		}
		else
			wyjscieZnacznik = false;
	
	}

	void PomocRozgrywka::rysujPomoc()
	{
		_dane->okno.draw(_tlo);
		_dane->okno.draw(_sterowanie);

		if (wybor == 1)
			_dane->okno.draw(_ster);
		if (wybor == 2)
			_dane->okno.draw(_punktacja);
		if (wybor == 3)
			_dane->okno.draw(_zapisy);

		if (znacznikPodswietlenie1 == false)
			_dane->okno.draw(_zmienLewo1);
		else
			_dane->okno.draw(_zmienLewo2);

		if (znacznikPodswietlenie2 == false)
			_dane->okno.draw(_zmienPrawo1);
		else
			_dane->okno.draw(_zmienPrawo2);	

		if (wyjscieZnacznik == false)
			_dane->okno.draw(_wyjscie1);
		else 
			_dane->okno.draw(_wyjscie2);
	}

	bool PomocRozgrywka::wyjscieGet()
	{
		return _wyjscie;
	}

	void PomocRozgrywka::wyjscieSet(bool wyjscie)
	{
		_wyjscie = wyjscie;
	}
}
