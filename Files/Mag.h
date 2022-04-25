#pragma once

#include <SFML/Graphics.hpp>
#include "Pêtla.h"
#include "Pocisk.h"

namespace Moje
{
	class Mag 
	{
	public:
		Mag(DG dane);

		void SpawnMag();
		void MagRysuj();
		void MagAnimuj();
		void MagRuch();
		void klatka(float czas, unsigned short int animacja, bool restart);
		void kolizjaPomoc(CircleShape pocisk);

		void magObrazenia(bool obrazenia);
		
		vector<Sprite> kolizja();
		vector<Sprite> kolizja2();
		vector<CircleShape> kolizjaPociski();

	private:
		DG _dane;

		vector<Sprite> magSprite[6];
		Pocisk* pocisk;

		bool obrazenia;
		float szybkosc;
		unsigned short int _animacja;
		Clock _klatka;
	};
}