#pragma once

#include <SFML/Graphics.hpp>
#include "Pêtla.h"
#include "Definicje.h"

namespace Moje
{
	class Glut 
	{
	public:
		Glut(DG dane);

		void SpawnGlut();
		void SpawnPomocniczy();
		void GlutRysuj();
		void GlutAnimuj();
		void GlutRuch();
		void klatka(float czas, unsigned short int animacja, bool restart);
		void kolizjaPomoc(CircleShape pocisk);

		vector<bool> obrazenia;

		vector<Sprite> kolizja();
		vector<Sprite> kolizja2();
	private:
		DG _dane;

		vector<Sprite> glutSprite[5];

		float szybkosc;
		unsigned short int _animacja;
		Clock _klatka;
	};
}