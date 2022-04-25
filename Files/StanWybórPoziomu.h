#pragma once

#include <SFML/Graphics.hpp>
#include "Stan.h"
#include "Pêtla.h"

#include "Definicje.h"
#include "G³ówneMenu.h"
#include "StanGry.h"

namespace Moje
{
	class Poziom : public Stan
	{
	public:
		Poziom(DG dane);

		void Inicjalizacja();
		void OgarnijWejscie();
		void Aktualizuj(float delta);
		void Rysuj(float delta);
	private:
		DG _dane;

		Sprite _tlo;
		Sprite _tytul;
		Sprite _powrot;
		Sprite _powrotNacisniety;
		Sprite _wyjscie1;
		Sprite _wyjscie2;

		Text _czcionkaNapis;
		Text _czcionkaLatwy;
		Text _czcionkaSredni;
		Text _czcionkaTrudny;

		Clock zegar;
		bool flagaPowrot;
		bool wyjscieZnacznik;
	};
}

