#pragma once

#include <SFML/Graphics.hpp>
#include "Stan.h"
#include "Pêtla.h"

namespace Moje
{
	class MenuRozgrywka
	{
	public:
		MenuRozgrywka(DG dane);

		void aktualizuj();
		void rysujMenu();

		unsigned short int wyborGet();
		unsigned short int zapisZnacznikGet();
		void akcjaSet(bool akcja);
		void zapisSet(bool zapis);
		
	private:
		DG _dane;

		Sprite _tlo;
		Sprite _okno;

		Text _wznow;
		Text _zapisz;
		Text _domenu;
		Text _wyjscie;

		Text _zapis;
		Text _zapis1;
		Text _zapis2;
		Text _zapis3;
		Text _wyjscieOkno;
		Text _rozumiem;

		Clock zegar;
		unsigned short int wybor;
		unsigned short int zapisZnacznik;
		bool akcja;
		bool zapisMozliwy;
	};
}

