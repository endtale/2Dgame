#pragma once

#include <SFML/Graphics.hpp>
#include "Pêtla.h"

namespace Moje
{
	class Gracz
	{
	public:
		Gracz(DG dane);

		void GraczRysyj();
		void GraczAnimuj();
		void klatka(Sprite* sprite, float czas, unsigned short int animacja, bool kierunek, bool restart);
		
		Sprite kolizja() { return _kolizja; }
	private:
		DG _dane;

		Sprite _graczStoi[4];	
		Sprite _graczBiegnie[6];
		Sprite _graczSkok[2];
		Sprite _kolizja;
		
		unsigned short int _animacja;
		bool _kierunek;
		bool _nacisniety;
		bool _skok;
		float _wysokosc , _maxWys, _minWys;
		Clock _klatka;
	};
}

