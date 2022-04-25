#pragma once

#include <SFML/Graphics.hpp>
#include "Stan.h"
#include "Pêtla.h"

namespace Moje
{
	class Wyniki : public Stan
	{
	public:
		Wyniki(DG dane);

		void Inicjalizacja();
		void OgarnijWejscie();
		void Aktualizuj(float delta);
		void Rysuj(float delta);

	private:
		DG _dane;
		Sprite _tlo;
		Sprite _powrot;
		Sprite _powrotNacisniety;

		Sprite _wyjscie1;
		Sprite _wyjscie2;

		Sprite _zmienPrawo1;
		Sprite _zmienPrawo2;
		Sprite _zmienLewo1;
		Sprite _zmienLewo2;

		Text _trudnosc;
		Text _wyniki[5];
		Text _usun;

		Clock zegar;

		int _punktyLatwy[5];
		int _punktySredni[5];
		int _punktyTrudny[5];

		bool flagaPowrotWyniki;
		bool wyjscieZnacznik;
		bool znacznikPodswietlenie1;
		bool znacznikPodswietlenie2;
		int wybor;
	};
}



