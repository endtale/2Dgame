#pragma once

#include <SFML/Graphics.hpp>
#include "Stan.h"
#include "Pêtla.h"

namespace Moje
{
	class Przegrana : public Stan
	{
	public:
		Przegrana(DG dane);

		void Inicjalizacja();
		void OgarnijWejscie();
		void Aktualizuj(float delta);
		void Rysuj(float delta);

	private:
		DG _dane;

		Sprite _tlo;
		Sprite _gameover;
		Sprite _powrot;
		Sprite _powrotNacisniety;
		Sprite _wyjscie1;
		Sprite _wyjscie2;

		Text _punkty;
		int punkty;
		bool wyjscieZnacznik;
	};
}