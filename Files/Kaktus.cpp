#include "Kaktus.h"

namespace Moje
{
	Kaktus::Kaktus(DG dane) : _dane(dane)
	{

	}

	void Kaktus::SpawnKaktus(float x)
	{
		Sprite sprite(_dane->aktyw.GetTexture("Kaktus"));
	
		float wysokosc;
		wysokosc = rand() % 50 + 1;
		sprite.setPosition(x, _dane->okno.getSize().y - sprite.getGlobalBounds().height / 2 - wysokosc);

		kaktusSprite.push_back(sprite);
	}

	void Kaktus::SpawnPomocniczy()
	{
		Sprite sprite(_dane->aktyw.GetTexture("Kaktus"));
		sprite.setPosition(_dane->okno.getSize().x, -1000);
		sprite.setColor(Color(0, 0, 0, 0));

		kaktusSprite.push_back(sprite);
	}

	void Kaktus::RuchKaktus()
	{
		float szybkosc;
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
				szybkosc = 0 - SZYBKOSC_PORUSZANIA_ELEMENTY;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left))
		{
				szybkosc =  SZYBKOSC_PORUSZANIA_ELEMENTY;
		}
		else
		{
				szybkosc = 0;
		}

		for (int i = 0; i < kaktusSprite.size(); i++)
		{
			if (kaktusSprite.at(i).getPosition().x < -150)
			{
				kaktusSprite.erase(kaktusSprite.begin() + i);
			}
			else
				kaktusSprite.at(i).move(szybkosc, 0);
		}
	}

	void Kaktus::RysujKaktus()
	{
		for (int i = 0; i < kaktusSprite.size(); i++)
		{
			_dane->okno.draw(kaktusSprite.at(i));
		}
	}

	vector<Sprite> Kaktus::kolizja()
	{
		return kaktusSprite;
	}
}
