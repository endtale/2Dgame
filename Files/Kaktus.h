#pragma once

#include <SFML/Graphics.hpp>
#include "Pêtla.h"
#include "Definicje.h"

namespace Moje
{
	class Kaktus
	{
	public:
		Kaktus(DG dane);

		void SpawnKaktus(float x);
		void SpawnPomocniczy();
		void RuchKaktus();
		void RysujKaktus();
		
		
		vector<Sprite> kolizja();

	private:
		DG _dane;
		
		vector<Sprite> kaktusSprite;
	};
}

