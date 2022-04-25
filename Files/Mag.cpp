#include "Mag.h"

namespace Moje
{
	Mag::Mag(DG dane) : _dane(dane)
	{
		_animacja = 0;
		pocisk = new Pocisk(_dane);
		obrazenia = false;
	}

	void Mag::SpawnMag()
	{
		Sprite sprite1(_dane->aktyw.GetTexture("Mag1"));
		Sprite sprite2(_dane->aktyw.GetTexture("Mag2"));
		Sprite sprite3(_dane->aktyw.GetTexture("Mag3"));
		Sprite sprite4(_dane->aktyw.GetTexture("Mag4"));
		Sprite sprite5(_dane->aktyw.GetTexture("Mag5"));
		Sprite sprite6(_dane->aktyw.GetTexture("MagRanny"));

		float wysokosc = WYS_OKNA - (sprite1.getGlobalBounds().height) - WYS_ZIEMI;
		sprite1.setPosition(_dane->okno.getSize().x, wysokosc);
		sprite2.setPosition(_dane->okno.getSize().x, wysokosc);
		sprite3.setPosition(_dane->okno.getSize().x, wysokosc);
		sprite4.setPosition(_dane->okno.getSize().x, wysokosc);
		sprite5.setPosition(_dane->okno.getSize().x, wysokosc);
		sprite6.setPosition(_dane->okno.getSize().x, wysokosc);

		magSprite[0].push_back(sprite1);
		magSprite[1].push_back(sprite2);
		magSprite[2].push_back(sprite3);
		magSprite[3].push_back(sprite4);
		magSprite[4].push_back(sprite5);
		magSprite[5].push_back(sprite6);

	}

	void Mag::klatka(float czas, unsigned short int animacja, bool restart)
	{
		if ((_klatka.getElapsedTime().asMilliseconds() > czas))
		{
			_animacja = animacja;
			if ((restart == true) && ((_klatka.getElapsedTime().asMilliseconds() > czas + CZAS_GRACZ_KLATKA)))
				_klatka.restart();
		}
	}

	void Mag::MagAnimuj()
	{
		if (obrazenia == false)
		{
			klatka(CZAS_GRACZ_KLATKA, 0, false);
			klatka(2 * CZAS_GRACZ_KLATKA, 1, false);
			klatka(3 * CZAS_GRACZ_KLATKA, 2, false);
			klatka(4 * CZAS_GRACZ_KLATKA, 3, false);
			klatka(5.5 * CZAS_GRACZ_KLATKA, 4, true);
			for (int i = 0; i < magSprite[0].size(); i++)
			{
				pocisk->pociskAnimuj(9, 7, 0, magSprite[3].at(i).getPosition().x + magSprite[3].at(i).getGlobalBounds().width / 2.5,
					magSprite[3].at(i).getPosition().y + magSprite[3].at(i).getGlobalBounds().height / 2.4, Color::Red, false, 1, Keyboard::P);
			}
		}
		else
			pocisk->strzal(7, 0, false);
	}

	void Mag::MagRuch()
	{

		float szybkosc;
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
				szybkosc = 0 - SZYBKOSC_PORUSZANIA_ELEMENTY;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left))
		{
				szybkosc = SZYBKOSC_PORUSZANIA_ELEMENTY;
		}
		else
		{		
				szybkosc = 0;
		}

		for (int i = 0; i < magSprite[0].size(); i++)
		{
			if (magSprite[0].at(i).getPosition().x < -150)
			{
				for (int j = 0; j < 6; j++)
					magSprite[j].erase(magSprite[j].begin() + i);

				obrazenia = false;
			}
			else
			{
				for (int j = 0; j < 6; j++)
					magSprite[j].at(i).move(szybkosc, 0);
			}
		}
	}

	void Mag::MagRysuj()
	{
		pocisk->pociskRysuj();
		for (int i = 0; i < magSprite[0].size(); i++)
		{
			if (obrazenia == false)
			{
				switch (_animacja)
				{
				case 0:
					_dane->okno.draw(magSprite[0].at(i));
					break;
				case 1:
					_dane->okno.draw(magSprite[1].at(i));
					break;
				case 2:
					_dane->okno.draw(magSprite[2].at(i));
					break;
				case 3:
					_dane->okno.draw(magSprite[3].at(i));
					break;
				case 4:
					_dane->okno.draw(magSprite[4].at(i));
					break;
				}
			}
			else
				_dane->okno.draw(magSprite[5].at(i));
		}
	}

	void Mag::magObrazenia(bool obrazenia)
	{
		this->obrazenia = obrazenia;
	}

	vector<CircleShape> Mag::kolizjaPociski()
	{
		return pocisk->kolizja();
	}

	vector<Sprite> Mag::kolizja()
	{
		return magSprite[2]; 
	}

	vector<Sprite> Mag::kolizja2()
	{
		return magSprite[3];
	}

	void Mag::kolizjaPomoc(CircleShape pocisk)
	{
		for (int i = 0; i < magSprite[3].size(); i++)
			if (_dane->wejscie.Kolizja(magSprite[3].at(i), pocisk))
				magSprite[3].at(i).setPosition(magSprite[3].at(i).getPosition().x, -500);
	}
}
