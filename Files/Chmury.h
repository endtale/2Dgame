#pragma once

#include <SFML/Graphics.hpp>
#include "Pêtla.h"

namespace Moje
{
	class Chmury
	{
	public:
		Chmury(DG dane);

		void ChmuryAnimuj();
		void ChmuryRysuj();
		void pozycja(Sprite* s, bool a, bool b, bool c);
		bool widoczny(Sprite sprite);

		friend class StanGry;
	private:
		DG _dane;

		Sprite _sprite[3];
		bool _kolizja;
	};
}