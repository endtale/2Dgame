#include "Pocisk.h"

namespace Moje
{
	Pocisk::Pocisk(DG dane) : _dane(dane)
	{
		_kierunek = false;
		_pierwszy = true;
	}

	void Pocisk::spawnPocisk(float promien, float x, float y, Color kolor)
	{
		CircleShape p(promien);
		Clock zegar;
		p.setPosition(x, y);
		p.setFillColor(kolor);

		pocisk.push_back(p);
		znacznik.push_back(3);
		czasG.push_back(zegar);
	}

	void Pocisk::pociskUsun(Sprite s)
	{
		for (int i = 0; i < pocisk.size(); i++)
		{
			if (_dane->wejscie.Kolizja(s, pocisk.at(i)))
			{
				pocisk.erase(pocisk.begin() + i);
				znacznik.erase(znacznik.begin() + i);
				czasG.erase(czasG.begin() + i);
			}
		}
	}

	void Pocisk::strzal(float predkosc, float g, bool gracz)
	{	
		if (Keyboard::isKeyPressed(Keyboard::Left))
			_kierunek = true;
		if (Keyboard::isKeyPressed(Keyboard::Right))
			_kierunek = false;

		for (int i = 0; i < pocisk.size(); i++)
		{
			if (znacznik.at(i) == 3)
			{
				czasG.at(i).restart();

				if (_kierunek == true)
					znacznik.at(i) = 1;
				if (_kierunek == false)
					znacznik.at(i) = 2;
				if (gracz == false)
					znacznik.at(i) = 2;
			}

			float spadek;
			spadek = g * czasG.at(i).getElapsedTime().asMilliseconds() / 1000;
			
			if ((pocisk.at(i).getPosition().y > WYS_OKNA - WYS_ZIEMI) ||
				(gracz == false && (pocisk.at(i).getPosition().x + pocisk.at(i).getGlobalBounds().width < 0 || 
					pocisk.at(i).getPosition().x > SZER_OKNA)))
			{
				pocisk.erase(pocisk.begin() + i);
				znacznik.erase(znacznik.begin() + i);
				czasG.erase(czasG.begin() + i);
			}
			else if (gracz == true)
			{

				if (znacznik.at(i) == 1 && Keyboard::isKeyPressed(Keyboard::Left))
					pocisk.at(i).move(-predkosc + SZYBKOSC_PORUSZANIA, spadek);
				else if (znacznik.at(i) == 2 && Keyboard::isKeyPressed(Keyboard::Left))
					pocisk.at(i).move(predkosc + SZYBKOSC_PORUSZANIA, spadek);
				else if (znacznik.at(i) == 1 && Keyboard::isKeyPressed(Keyboard::Right))
					pocisk.at(i).move(-predkosc - SZYBKOSC_PORUSZANIA, spadek);
				else if (znacznik.at(i) == 2 && Keyboard::isKeyPressed(Keyboard::Right))
					pocisk.at(i).move(predkosc - SZYBKOSC_PORUSZANIA, spadek);
				else if (znacznik.at(i) == 1)
					pocisk.at(i).move(-predkosc, spadek);
				else if (znacznik.at(i) == 2)
						pocisk.at(i).move(predkosc, spadek);
			}
			else
			{

				if (Keyboard::isKeyPressed(Keyboard::Right))
					pocisk.at(i).move(-predkosc - SZYBKOSC_PORUSZANIA, spadek);
				else if (Keyboard::isKeyPressed(Keyboard::Left))
					pocisk.at(i).move(-predkosc + SZYBKOSC_PORUSZANIA, spadek);
				else
					pocisk.at(i).move(-predkosc, spadek);
			}
		}
	}

	void Pocisk::pociskAnimuj(float promien, float predkosc, float g, float x, float y, Color kolor, bool gracz, float czestotliwosc, Keyboard::Key przycisk)
	{
		if ((gracz == false || Keyboard::isKeyPressed(przycisk)) && _pierwszy == true)
		{
			_pierwszy = false;
			spawnPocisk(promien, x, y, kolor);
			czas.restart();
		}

		if ((gracz == false || Keyboard::isKeyPressed(przycisk)) && czas.getElapsedTime().asSeconds() > czestotliwosc && _pierwszy == false)
		{
			spawnPocisk(promien, x, y, kolor);
			czas.restart();
		}	

		strzal(predkosc, g, gracz);
	}

	void Pocisk::pociskRysuj()
	{
		for (int i = 0; i < pocisk.size(); i++)
		{
			_dane->okno.draw(pocisk.at(i));
		}
	}

	vector<CircleShape> Pocisk::kolizja()
	{
		return pocisk;
	}
}
