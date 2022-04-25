#include "SpritePunty.h"

namespace Moje
{
	SpritePunkty::SpritePunkty(DG dane) : _dane(dane)
	{
		
	}

	void SpritePunkty::spawnPunkt(float x)
	{
		RectangleShape pros(Vector2f(20, WYS_OKNA));
		pros.setPosition(x, 0);
		punkty.push_back(pros);
	}

	void SpritePunkty::ruchPunkt(Sprite s)
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

		for (int i = 0; i < punkty.size(); i++)
		{
			if (_dane->wejscie.Kolizja(s, punkty.at(i)))
			{
				punkty.erase(punkty.begin() + i);
			}
			else
				punkty.at(i).move(szybkosc, 0);
		}
	}

	vector<RectangleShape> SpritePunkty::kolizja()
	{
		return punkty;
	}


}
