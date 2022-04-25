#pragma once

#include <SFML/Graphics.hpp>
#include "Stan.h"
#include "Pêtla.h"

namespace Moje
{
	class Logo : public Stan
	{
	public:
		Logo(DG dane);

		void Inicjalizacja();
		void OgarnijWejscie();
		void Aktualizuj(float delta);
		void Rysuj(float delta);

	private:
		DG _dane;
		Clock _zegar;
		Sprite _tlo;
	};
}