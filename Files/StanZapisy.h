#pragma once

#include <SFML/Graphics.hpp>
#include "Stan.h"
#include "Pêtla.h"

namespace Moje
{
	class Zapisy : public Stan
	{
	public:
		Zapisy(DG dane);

		void Inicjalizacja();
		void OgarnijWejscie();
		void Aktualizuj(float delta);
		void Rysuj(float delta);

		void poziom(int i);
	private:
		DG _dane;
		Sprite _tlo;
		Sprite _powrot;
		Sprite _powrotNacisniety;

		Sprite _wyjscie1;
		Sprite _wyjscie2;

		Text _logo;
		Text _zapis1;
		Text _zapis2;
		Text _zapis3;
		Text _nieIstnieje;
		Text _usun;

		Clock zegar;
		Clock zegar2;

		bool flagaPowrotZapisy;
		bool wyjscieZnacznik;
		bool zapisIstnieje;
		int buf[5];
	};
}

