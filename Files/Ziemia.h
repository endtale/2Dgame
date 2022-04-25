#pragma once

#include <SFML/Graphics.hpp>
#include "Pêtla.h"

namespace Moje
{
	class Ziemia
	{
	public:
		Ziemia(DG dane);

		void ZiemiaAnimuj();
		void ZiemiaRysuj();

	private:
		DG _dane;

		vector<Sprite> ziemiaSprite;
	};
}


