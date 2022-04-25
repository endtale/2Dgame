#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include "Definicje.h"

using namespace std;
using namespace sf;

namespace Moje
{
	class MenadzerWejscia
	{
	public:
		MenadzerWejscia() {}
		~MenadzerWejscia() {}

		bool CzyNajechany(Sprite obiekt, RenderWindow& okno);
		bool CzyNajechanyOdwrocony(Sprite obiekt, RenderWindow& okno);
		bool CzyNajechany(Text tekst, RenderWindow& okno);
		bool CzyKlawiszNacisniety();

		bool skok(Sprite* s, Sprite* s1, float wysPocz, float predPocz, float przyspieszenie);

		bool Kolizja(Sprite sprite1, Sprite sprite2);
		bool Kolizja(Sprite sprite1, CircleShape kolo);
		bool Kolizja(Sprite sprite1, RectangleShape pros);

		void zapis(const char* nazwa, const char* tryb, int punkty);
		void zapisPunkty(const char* nazwa, int punkty);
		void odczytPocz(const char* nazwa);
		void odczyt(const char* nazwa, int rozmiar, int* zmienna);
		void zapisGry(const char* nazwa, int punkty, int znacznikPunkty, int hp, int poziom);
		void zapisUsun(const char* nazwa);
		
		void sortuj(int tab[], int n);

		Trudnosc poziomGet();
		void poziomSet(Trudnosc poziom);
		int punktyGet();
		void punktySet(int punkty);
		int znacznikPunktyGet();
		void znacznikPunktySet(int znacznikPunkty);
		int hpGet();
		void hpSet(int hp);


	private:
		Trudnosc poziom;
		int punkty;
		int znacznikPunkty;
		int hp;

		unsigned short int skacze;
		Clock _skokZegar;
	};
}
