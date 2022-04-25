#pragma once

#include <SFML/Graphics.hpp>
#include "Pêtla.h"
#include "Definicje.h"

using namespace sf;

namespace Moje
{
	class Pocisk
	{
	public:
		Pocisk(DG dane);

		void spawnPocisk(float promien, float x, float y, Color kolor);
		void strzal(float predkosc, float g, bool gracz);
		void pociskAnimuj(float promien, float predkosc, float g, float x, float y, Color kolor, bool gracz, float czestotliwosc , Keyboard::Key przycisk);
		void pociskUsun(Sprite s);
		void pociskRysuj();	

		vector<CircleShape> kolizja();
	private:
		DG _dane;

		vector<CircleShape> pocisk;
		vector<unsigned short int> znacznik;

		bool _kierunek;
		bool _pierwszy;

		Clock czas;
		vector<Clock> czasG;
	};
}

