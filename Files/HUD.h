#pragma once

#include <SFML/Graphics.hpp>
#include "Pêtla.h"
#include "Definicje.h"

namespace Moje
{
	class HUD
	{
	public:
		HUD(DG dane);

		void rysujHUD();
		void aktualizujPunkty(int punkty, int hp);
	private:
		DG _dane;

		Text _punktyTekst;
		Text _hpTekst;
		Text _pomoc;
		Text _menu;
	};
}

