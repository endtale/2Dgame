#include "Glut.h"

namespace Moje
{
	Glut::Glut(DG dane) : _dane(dane)
	{
		_animacja = 0;
	}

	void Glut::SpawnGlut()
	{
		Sprite sprite1(_dane->aktyw.GetTexture("Glut1"));
		Sprite sprite2(_dane->aktyw.GetTexture("Glut2"));
		Sprite sprite3(_dane->aktyw.GetTexture("Glut3"));
		Sprite sprite4(_dane->aktyw.GetTexture("Glut4"));
		Sprite sprite5(_dane->aktyw.GetTexture("GlutObrazenia"));

		float wysokosc = WYS_OKNA - (sprite1.getGlobalBounds().height) - WYS_ZIEMI;
		sprite1.setPosition(_dane->okno.getSize().x, wysokosc);
		sprite2.setPosition(_dane->okno.getSize().x, wysokosc);
		sprite3.setPosition(_dane->okno.getSize().x, wysokosc);
		sprite4.setPosition(_dane->okno.getSize().x, wysokosc);
		sprite5.setPosition(_dane->okno.getSize().x, wysokosc);

		glutSprite[0].push_back(sprite1);
		glutSprite[1].push_back(sprite2);
		glutSprite[2].push_back(sprite3);
		glutSprite[3].push_back(sprite4);
		glutSprite[4].push_back(sprite5);
		obrazenia.push_back(false);
	}

	void Glut::SpawnPomocniczy()
	{
		Sprite sprite1(_dane->aktyw.GetTexture("Glut1"));
		Sprite sprite2(_dane->aktyw.GetTexture("Glut2"));
		Sprite sprite3(_dane->aktyw.GetTexture("Glut3"));
		Sprite sprite4(_dane->aktyw.GetTexture("Glut4"));
		Sprite sprite5(_dane->aktyw.GetTexture("GlutObrazenia"));

		float wysokosc = -1000;
		sprite1.setPosition(_dane->okno.getSize().x, wysokosc);
		sprite2.setPosition(_dane->okno.getSize().x, wysokosc);
		sprite3.setPosition(_dane->okno.getSize().x, wysokosc);
		sprite4.setPosition(_dane->okno.getSize().x, wysokosc);
		sprite5.setPosition(_dane->okno.getSize().x, wysokosc);

		sprite1.setColor(Color(0, 0, 0, 0));
		sprite2.setColor(Color(0, 0, 0, 0));
		sprite3.setColor(Color(0, 0, 0, 0));
		sprite4.setColor(Color(0, 0, 0, 0));
		sprite5.setColor(Color(0, 0, 0, 0));

		glutSprite[0].push_back(sprite1);
		glutSprite[1].push_back(sprite2);
		glutSprite[2].push_back(sprite3);
		glutSprite[3].push_back(sprite4);
		glutSprite[4].push_back(sprite5);
		obrazenia.push_back(false);
	}

	void Glut::klatka(float czas, unsigned short int animacja, bool restart)
	{
			if ((_klatka.getElapsedTime().asMilliseconds() > czas))
			{
				_animacja = animacja;
				if ((restart == true) && ((_klatka.getElapsedTime().asMilliseconds() > czas + CZAS_GRACZ_KLATKA)))
					_klatka.restart();
			}
	}

	void Glut::GlutAnimuj()
	{
			klatka(CZAS_GRACZ_KLATKA, 0, false);
			klatka(2 * CZAS_GRACZ_KLATKA, 1, false);
			klatka(3 * CZAS_GRACZ_KLATKA, 2, false);
			klatka(4 * CZAS_GRACZ_KLATKA, 3, true);
	}

	void Glut::GlutRuch()
	{

		float szybkosc = 0;
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

		for (int i = 0; i < glutSprite[0].size(); i++)
		{
			if (glutSprite[0].at(i).getPosition().x < -150)
			{
				obrazenia.erase(obrazenia.begin() + i);

				for (int j = 0; j < 5; j++)
					glutSprite[j].erase(glutSprite[j].begin() + i);
			}
			else
			{
				for (int j = 0; j < 5; j++)
					glutSprite[j].at(i).move(szybkosc, 0);
			}

		}
	}


	void Glut::GlutRysuj()
	{
		for (int i = 0; i < glutSprite[0].size(); i++)
		{
			if (obrazenia.at(i) == false)
			{
				switch (_animacja)
				{
				case 0:
					_dane->okno.draw(glutSprite[0].at(i));
					break;
				case 1:
					_dane->okno.draw(glutSprite[1].at(i));
					break;
				case 2:
					_dane->okno.draw(glutSprite[2].at(i));
					break;
				case 3:
					_dane->okno.draw(glutSprite[3].at(i));
					break;
				}
			}
			else
				_dane->okno.draw(glutSprite[4].at(i));
		}
	}

	vector<Sprite> Glut::kolizja()
	{
		return glutSprite[0];
	}

	vector<Sprite> Glut::kolizja2()
	{
		return glutSprite[1];
	}

	void Glut::kolizjaPomoc(CircleShape pocisk)
	{
		for (int i = 0; i < glutSprite[1].size(); i++)
			if (_dane->wejscie.Kolizja(glutSprite[1].at(i), pocisk))
				glutSprite[1].at(i).setPosition(glutSprite[1].at(i).getPosition().x, -500);
	}
}