#pragma once

#include <SFML/Graphics.hpp>
#include "Pêtla.h"
#include "Definicje.h"

namespace Moje
{
	class SpritePunkty
	{
	public:
		SpritePunkty(DG dane);

		void spawnPunkt(float x);
		void ruchPunkt(Sprite s);

		vector<RectangleShape> kolizja();
	private:
		DG _dane;

		vector<RectangleShape> punkty;
	};
}
