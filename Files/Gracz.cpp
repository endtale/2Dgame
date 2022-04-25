#include "Gracz.h"
#include "Definicje.h"
#include "iostream"

namespace Moje
{
	Gracz::Gracz(DG dane) : _dane(dane)
	{
		_animacja = 0;
		_kierunek = false;
		_nacisniety = false;
		_skok = false;

		_dane->aktyw.ladujTeksture("Gracz Stoi 1", GRACZSTOI_1_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Gracz Stoi 2", GRACZSTOI_2_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Gracz Stoi 3", GRACZSTOI_3_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Gracz Stoi 4", GRACZSTOI_4_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Gracz Biegnie 1", GRACZBIEGNIE_1_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Gracz Biegnie 2", GRACZBIEGNIE_2_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Gracz Biegnie 3", GRACZBIEGNIE_3_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Gracz Biegnie 4", GRACZBIEGNIE_4_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Gracz Biegnie 5", GRACZBIEGNIE_5_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Gracz Biegnie 6", GRACZBIEGNIE_6_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Gracz Skacze 1", GRACZSKACZE_LOKALIZACJA);

		_graczStoi[0].setTexture(this->_dane->aktyw.GetTexture("Gracz Stoi 1"));
		_graczStoi[1].setTexture(this->_dane->aktyw.GetTexture("Gracz Stoi 2"));
		_graczStoi[2].setTexture(this->_dane->aktyw.GetTexture("Gracz Stoi 3"));
		_graczStoi[3].setTexture(this->_dane->aktyw.GetTexture("Gracz Stoi 4"));
		_graczBiegnie[0].setTexture(this->_dane->aktyw.GetTexture("Gracz Biegnie 1"));
		_graczBiegnie[1].setTexture(this->_dane->aktyw.GetTexture("Gracz Biegnie 2"));
		_graczBiegnie[2].setTexture(this->_dane->aktyw.GetTexture("Gracz Biegnie 3"));
		_graczBiegnie[3].setTexture(this->_dane->aktyw.GetTexture("Gracz Biegnie 4"));
		_graczBiegnie[4].setTexture(this->_dane->aktyw.GetTexture("Gracz Biegnie 5"));
		_graczBiegnie[5].setTexture(this->_dane->aktyw.GetTexture("Gracz Biegnie 6"));
		_graczSkok[0].setTexture(this->_dane->aktyw.GetTexture("Gracz Skacze 1"));

		_kolizja.setTexture(this->_dane->aktyw.GetTexture("Gracz Skacze 1"));

		_wysokosc = WYS_OKNA - (_graczStoi[0].getGlobalBounds().height) - WYS_ZIEMI;
		_minWys = WYS_OKNA - (_graczStoi[0].getGlobalBounds().height) - WYS_ZIEMI;
		_maxWys = 180;

		for (int i = 0; i < 4; i++)
		{
			_graczStoi[i].setPosition(SZER_OKNA / 2 - (_graczStoi[i].getGlobalBounds().width / 2), _wysokosc);
		}
		for (int i = 0; i < 6; i++)
		{
			_graczBiegnie[i].setPosition(SZER_OKNA / 2 - (_graczBiegnie[i].getGlobalBounds().width / 2), _wysokosc);
		}
		_graczSkok[0].setPosition(SZER_OKNA / 2 - (_graczSkok[0].getGlobalBounds().width / 2), _wysokosc);
		_kolizja.setPosition(SZER_OKNA / 2 - (_graczSkok[0].getGlobalBounds().width / 2), _wysokosc);
		_kolizja.setColor(Color(0, 0, 0, 0));
	}


	void Gracz::klatka(Sprite* sprite, float czas, unsigned short int animacja, bool kierunek, bool restart)
	{
		if (kierunek == false)
		{
			if ((_klatka.getElapsedTime().asMilliseconds() > czas))
			{
				(*sprite).setPosition(SZER_OKNA / 2 - ((*sprite).getGlobalBounds().width / 2), _wysokosc);
				(*sprite).setScale(+1.0, 1.0);
				_animacja = animacja;
				if (restart == true)
					_klatka.restart();
			}
		}

		if (kierunek == true)
		{
			if ((_klatka.getElapsedTime().asMilliseconds() > czas))
			{
				(*sprite).setPosition(SZER_OKNA / 2 + ((*sprite).getGlobalBounds().width / 2), _wysokosc);
				(*sprite).setScale(-1.0, 1.0);
				_animacja = animacja;
				if (restart == true)
					_klatka.restart();
			}
		}
	}

	void Gracz::GraczAnimuj()
	{
		_nacisniety = _dane->wejscie.CzyKlawiszNacisniety();

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			_kierunek = false;
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			_kierunek = true;
		}

		if (_dane->wejscie.skok(&_graczSkok[0], &_kolizja ,_minWys, 9.0f, 0.25f) == true)
		{
			_wysokosc = _graczSkok[0].getPosition().y;
			if (_kierunek == false)
			{
				_graczSkok[0].setScale(1.0, 1.0);
				_graczSkok[0].setPosition(SZER_OKNA / 2 - (_graczSkok[0].getGlobalBounds().width / 2), _graczSkok[0].getPosition().y);
			}
			if (_kierunek == true)
			{
				_graczSkok[0].setScale(-1.0, 1.0);
				_graczSkok[0].setPosition(SZER_OKNA / 2 + (_graczSkok[0].getGlobalBounds().width / 2), _graczSkok[0].getPosition().y);
			}
			_animacja = 10;	
		}

		else if (_graczSkok[0].getPosition().y + _graczSkok[0].getGlobalBounds().height <= WYS_OKNA - WYS_ZIEMI)
		{
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				klatka(&_graczBiegnie[0], 1 * CZAS_GRACZ_KLATKA, 4, _kierunek, false);
				klatka(&_graczBiegnie[1], 2 * CZAS_GRACZ_KLATKA, 5, _kierunek, false);
				klatka(&_graczBiegnie[2], 3 * CZAS_GRACZ_KLATKA, 6, _kierunek, false);
				klatka(&_graczBiegnie[3], 4 * CZAS_GRACZ_KLATKA, 7, _kierunek, false);
				klatka(&_graczBiegnie[4], 5 * CZAS_GRACZ_KLATKA, 8, _kierunek, false);
				klatka(&_graczBiegnie[5], 6 * CZAS_GRACZ_KLATKA, 9, _kierunek, true);
			}

			else if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				klatka(&_graczBiegnie[0], 1 * CZAS_GRACZ_KLATKA, 4, _kierunek, false);
				klatka(&_graczBiegnie[1], 2 * CZAS_GRACZ_KLATKA, 5, _kierunek, false);
				klatka(&_graczBiegnie[2], 3 * CZAS_GRACZ_KLATKA, 6, _kierunek, false);
				klatka(&_graczBiegnie[3], 4 * CZAS_GRACZ_KLATKA, 7, _kierunek, false);
				klatka(&_graczBiegnie[4], 5 * CZAS_GRACZ_KLATKA, 8, _kierunek, false);
				klatka(&_graczBiegnie[5], 6 * CZAS_GRACZ_KLATKA, 9, _kierunek, true);
			}


			else if ((_kierunek == false) && (_nacisniety == false))
			{
				klatka(&_graczStoi[0], 1 * CZAS_GRACZ_KLATKA, 0, _kierunek, false);
				klatka(&_graczStoi[1], 2 * CZAS_GRACZ_KLATKA, 1, _kierunek, false);
				klatka(&_graczStoi[2], 3 * CZAS_GRACZ_KLATKA, 2, _kierunek, false);
				klatka(&_graczStoi[3], 4 * CZAS_GRACZ_KLATKA, 3, _kierunek, true);
			}

			else if ((_kierunek == true) && (_nacisniety == false))
			{
				klatka(&_graczStoi[0], 1 * CZAS_GRACZ_KLATKA, 0, _kierunek, false);
				klatka(&_graczStoi[1], 2 * CZAS_GRACZ_KLATKA, 1, _kierunek, false);
				klatka(&_graczStoi[2], 3 * CZAS_GRACZ_KLATKA, 2, _kierunek, false);
				klatka(&_graczStoi[3], 4 * CZAS_GRACZ_KLATKA, 3, _kierunek, true);
			}
		}
	}

	void Gracz::GraczRysyj()
	{
		switch (_animacja)
		{
		case 0:
			_dane->okno.draw(_graczStoi[0]);
			break;
		case 1:
			_dane->okno.draw(_graczStoi[1]);
			break;
		case 2:
			_dane->okno.draw(_graczStoi[2]);
			break;
		case 3:
			_dane->okno.draw(_graczStoi[3]);
			break;
		case 4:
			_dane->okno.draw(_graczBiegnie[0]);
			break;
		case 5:
			_dane->okno.draw(_graczBiegnie[1]);
			break;
		case 6:
			_dane->okno.draw(_graczBiegnie[2]);
			break;
		case 7:
			_dane->okno.draw(_graczBiegnie[3]);
			break;
		case 8:
			_dane->okno.draw(_graczBiegnie[4]);
			break;
		case 9:
			_dane->okno.draw(_graczBiegnie[5]);
			break;
		case 10:
			_dane->okno.draw(_graczSkok[0]);
			break;
		}
	}
}