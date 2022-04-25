#pragma once

#include <map>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace Moje
{
	class Aktywy
	{
	public:
		Aktywy() {}
		~Aktywy() {}

		void ladujTeksture(string nazwa, string plik);
		Texture &GetTexture(string nazwa);

		void ladujCzcionke(string nazwa, string plik);
		Font &GetFont(string name);

	private:
		map<string, Texture> _tekstury;
		map<string, Font> _czcionki;
	};
}

