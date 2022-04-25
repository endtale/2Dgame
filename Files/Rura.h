#pragma once

#include <SFML/Graphics.hpp>
#include "Pêtla.h"

namespace Moje
{
	class Rura
	{
	public:
		Rura(DG dane);

		void RuraAnimuj();
		void RuraRysuj();

		Sprite kolizja() { return _spriteRura; }

	private:
		DG _dane;

		Sprite _spriteRura;
		float _wysokosc;
	};
}