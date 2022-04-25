#pragma once

#include <SFML/Graphics.hpp>

#include "Stan.h"
#include "Pêtla.h"

#include "Definicje.h"
#include "StanZapisy.h"
#include "StanWyniki.h"
#include "StanWybórPoziomu.h"

namespace Moje
{
	class MenuGlowne : public Stan
	{
	public:
		MenuGlowne(DG dane);

		void Inicjalizacja();
		void OgarnijWejscie();
		void Aktualizuj(float delta);
		void Rysuj(float delta);

	private:
		DG _dane;
		Sprite _tlo;
		Sprite _tytul;

		Sprite _grajPrzycisk;
		Sprite _grajPrzycisk2;

		Sprite _zapisyPrzycisk;
		Sprite _zapisyPrzycisk2;

		Sprite _wynikiPrzycisk;
		Sprite _wynikiPrzycisk2;

		Sprite _wyjscie1;
		Sprite _wyjscie2;

		Clock zegar;

		bool flaga;
		bool flaga2;
		bool flaga3 ;
		bool wyjscieZnacznik;

	};
}

