#pragma once

#include <SFML/Graphics.hpp>
#include "Stan.h"
#include "Pêtla.h"

namespace Moje
{
	class PomocRozgrywka
	{
	public:
		PomocRozgrywka(DG dane);

		void aktualizuj();
		void rysujPomoc();

		bool wyjscieGet();
		void wyjscieSet(bool wyjscie);
	private:
		DG _dane;

		Sprite _tlo;
		Sprite _ster;
		Sprite _punktacja;
		Sprite _zapisy;
		Sprite _zmienPrawo1;
		Sprite _zmienPrawo2;
		Sprite _zmienLewo1;
		Sprite _zmienLewo2;
		Sprite _wyjscie1;
		Sprite _wyjscie2;

		Text _sterowanie;

		

		Clock zegar;
		unsigned short int wybor;
		bool znacznikPodswietlenie1;
		bool znacznikPodswietlenie2;
		bool wyjscieZnacznik;
		bool _wyjscie;
	};
}

