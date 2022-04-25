#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "MaszynaStanu.h"
#include "Menad�erWej�cia.h"
#include "Aktywy.h"


namespace Moje
{
	struct DaneGry
	{
		RenderWindow okno;
		MaszynaStanu maszyna;
		MenadzerWejscia wejscie;
		Aktywy aktyw;
	};

	typedef shared_ptr<DaneGry> DG;  // wska�nik dzielony do struktury

	class Gra
	{
	public:
		Gra(int szer, int wys, string tytul);

	private:
		const float delta = 1.0f / 60.0f; // klatki
		Clock _zegar;
		DG _dane = make_shared<DaneGry>(); // alokuje i tworzy obiekt i zwrazca wska�nik dzielony/ rzeczywisty dost�p do struktury
		void Uruchom();
	};
}

