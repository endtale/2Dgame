#pragma once

#include <SFML/Graphics.hpp>

#include "Menad¿erWejœcia.h"
#include "Stan.h"
#include "Pêtla.h"
#include "Ziemia.h"
#include "Chmury.h"
#include "Gracz.h"
#include "Rura.h"
#include "Glut.h"
#include "Kaktus.h"
#include "Mag.h"
#include "Pocisk.h"
#include "SpritePunty.h"
#include "HUD.h"
#include "G³ówneMenu.h"
#include "MenuRozgrywka.h"
#include "PomocRozgrywka.h"

namespace Moje
{
	class StanGry : public Stan
	{
	public:
		StanGry(DG dane);

		void Inicjalizacja();
		void OgarnijWejscie();
		void Aktualizuj(float delta);
		void Rysuj(float delta);

		void kolizja();
		void hp();
		bool czyZapisMozliwy();

	private:
		DG _dane;

		//typ wyliczeniowy
		Rozgrywka rozgrywka;
		Trudnosc poziom;
		int poziomInt;

		//menu i pomoc
		MenuRozgrywka* menu;
		PomocRozgrywka* pomoc;

		//gracz
		Gracz* gracz;
		Pocisk* pocisk;

		//przeciwnicy
		Glut* glut;
		Kaktus* kaktus;
		Mag* mag;
		
		//t³o
		Ziemia* ziemia;
		Chmury* chmury;
		Rura* rura;
		Sprite _tlo;

		//spawn mobów
		Clock _resp;

		//punkty i hp
		HUD* hud;
		SpritePunkty* punktySprite;
		int _punkty;
		int _hp;
		int _maxHp;
		Clock _zegarHp;
		bool znacznikHp;
		unsigned short int znacznikPunkty;

		//znaczniki
		int mob;
		unsigned short int znacznik;
		unsigned short int znacznikMag;
		unsigned short int znacznikGlut;
	};
}