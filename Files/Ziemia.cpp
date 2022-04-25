#include "Ziemia.h"
#include "Definicje.h"
#include "Menad¿erWejœcia.h"

#include <iostream>
using namespace std;

namespace Moje
{
	Ziemia::Ziemia(DG dane) : _dane(dane)
	{
		
	
		Sprite _sprite1(_dane->aktyw.GetTexture("Ziemia"));
		Sprite _sprite2(_dane->aktyw.GetTexture("Ziemia"));
		Sprite _sprite3(_dane->aktyw.GetTexture("Ziemia"));
		
		_sprite1.setPosition(0 - _sprite1.getGlobalBounds().width, _dane->okno.getSize().y - _sprite1.getGlobalBounds().height);
		_sprite2.setPosition(0, _dane->okno.getSize().y - _sprite2.getGlobalBounds().height);
		_sprite3.setPosition(0 + _sprite1.getGlobalBounds().width, _dane->okno.getSize().y - _sprite3.getGlobalBounds().height);
		
		ziemiaSprite.push_back(_sprite1);
		ziemiaSprite.push_back(_sprite2);
		ziemiaSprite.push_back(_sprite3);
	}


	void Ziemia::ZiemiaAnimuj()
	{

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			for (int i = 0; i < ziemiaSprite.size(); i++)
			{
				ziemiaSprite.at(i).move(SZYBKOSC_PORUSZANIA, 0);
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			for (int i = 0; i < ziemiaSprite.size(); i++)
			{
				if (ziemiaSprite.at(i).getPosition().x < 0 - 1.5 * ziemiaSprite.at(i).getGlobalBounds().width)
				{
					ziemiaSprite.erase(ziemiaSprite.begin() + i);
					Sprite sprite(_dane->aktyw.GetTexture("Ziemia"));
					sprite.setPosition(0 - SZYBKOSC_PORUSZANIA + 1.5 * sprite.getGlobalBounds().width, _dane->okno.getSize().y - sprite.getGlobalBounds().height);
					ziemiaSprite.push_back(sprite);
				}

				ziemiaSprite.at(i).move(0 - SZYBKOSC_PORUSZANIA, 0);
			}
		}

		
	}

	void Ziemia::ZiemiaRysuj()
	{
		for (int i = 0; i < ziemiaSprite.size(); i++)
		{
			_dane->okno.draw(ziemiaSprite.at(i));
		}
	}
}
