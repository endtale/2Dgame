#include "Chmury.h"
#include "Definicje.h"
#include "Menad¿erWejœcia.h"

#include <iostream>
using namespace std;

namespace Moje
{
	Chmury::Chmury(DG dane) : _dane(dane)
	{
		_kolizja = false;

		_dane->aktyw.ladujTeksture("Chmury", CHMURY_LOKALIZACJA);
		for (int i = 0; i < 3; i++)
		{
			_sprite[i].setTexture(this->_dane->aktyw.GetTexture("Chmury"));
		}

		_sprite[0].setPosition(0, 0);
		_sprite[1].setPosition(_sprite[0].getGlobalBounds().width,0);
		_sprite[2].setPosition(_sprite[0].getPosition().x - _sprite[0].getGlobalBounds().width, 0);
	}

	bool Chmury::widoczny(Sprite sprite)
	{
		if ((sprite.getPosition().x < 0 - sprite.getGlobalBounds().width) || (sprite.getPosition().x > _dane->okno.getSize().x))
		{
			return false;
		}
		else { return true; }
	}

	void Chmury::pozycja(Sprite* s, bool a, bool b, bool c)
	{
		if (a == true && b == true && c == false)
		{
			(*s).setPosition((*s).getGlobalBounds().width, 0);
		}
	}

	void Chmury::ChmuryAnimuj()
	{
		float szybkosc = -1.25;
		bool widoczny_1 = widoczny(_sprite[0]);
		bool widoczny_2 = widoczny(_sprite[1]);
		bool widoczny_3 = widoczny(_sprite[2]);

		if ((Keyboard::isKeyPressed(Keyboard::Right)) && (_kolizja == false))
		{
			szybkosc = -2;
		}

		if ((Keyboard::isKeyPressed(Keyboard::Left)) && (_kolizja == false))
		{
			szybkosc = -0.5;
		}

		pozycja(&_sprite[2], widoczny_1, widoczny_2, widoczny_3);
		pozycja(&_sprite[0], widoczny_3, widoczny_2, widoczny_1);
		pozycja(&_sprite[1], widoczny_1, widoczny_3, widoczny_2);

		_sprite[0].move(szybkosc, 0.0f);
		_sprite[1].move(szybkosc, 0.0f);
		_sprite[2].move(szybkosc, 0.0f);
	}

	void Chmury::ChmuryRysuj()
	{
		_dane->okno.draw(_sprite[0]);
		_dane->okno.draw(_sprite[1]);
		_dane->okno.draw(_sprite[2]);
	}
}
