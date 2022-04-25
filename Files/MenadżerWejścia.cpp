#define _CRT_SECURE_NO_WARNINGS
#include "Menad¿erWejœcia.h"


namespace Moje
{
	//////////////////////////// MYSZKA I KLAWIATURA /////////////////////////////////////////////////////////
	bool MenadzerWejscia::CzyNajechany(Sprite obiekt, RenderWindow& okno)
	{
		IntRect Prost(obiekt.getPosition().x, obiekt.getPosition().y, obiekt.getGlobalBounds().width, obiekt.getGlobalBounds().height);

		if (Prost.contains(Mouse::getPosition(okno)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool MenadzerWejscia::CzyNajechanyOdwrocony(Sprite obiekt, RenderWindow& okno)
	{
		IntRect Prost(obiekt.getPosition().x - obiekt.getGlobalBounds().width, obiekt.getPosition().y, obiekt.getGlobalBounds().width, obiekt.getGlobalBounds().height);

		if (Prost.contains(Mouse::getPosition(okno)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool MenadzerWejscia::CzyNajechany(Text tekst, RenderWindow& okno)
	{
		IntRect Prost(tekst.getPosition().x - tekst.getGlobalBounds().width / 2, tekst.getPosition().y, tekst.getGlobalBounds().width, tekst.getGlobalBounds().height);

		if (Prost.contains(Mouse::getPosition(okno)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool MenadzerWejscia::CzyKlawiszNacisniety()
	{
		if ((Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::Left)) || (Keyboard::isKeyPressed(Keyboard::Up)))
			return true;
		else
			return false;
	}

	//////////////////////////// SKOK /////////////////////////////////////////////////////////
	float a = 0;
	bool MenadzerWejscia::skok(Sprite* s, Sprite* s1, float wysPocz, float predPocz, float przyspieszenie)
	{
		float wysAktualna;
		float czas = 5.0f;
		float predkosc;

		if ((*s).getPosition().y + (*s).getGlobalBounds().height > WYS_OKNA - WYS_ZIEMI)
		{
			(*s).setPosition((*s).getPosition().x, WYS_OKNA - WYS_ZIEMI - (*s).getGlobalBounds().height);
			(*s1).setPosition((*s1).getPosition().x, WYS_OKNA - WYS_ZIEMI - (*s1).getGlobalBounds().height);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && (skacze == 0))
		{
			skacze = 1;
			_skokZegar.restart();
			a = 0;
			return true;
		}
		if ((_skokZegar.getElapsedTime().asMilliseconds() > czas) && (skacze == 1))
		{
			predkosc = predPocz - (przyspieszenie * a);
			(*s).move(0, 0 - predkosc);
			(*s1).move(0, 0 - predkosc);
			a++;
			_skokZegar.restart();
			if (predkosc == 0)
			{
				skacze = 2;
				a = 0;
			}
			return true;
		}
		if ((_skokZegar.getElapsedTime().asMilliseconds() > czas) && (skacze == 2))
		{
			predkosc = 0 + (przyspieszenie * a);
			wysAktualna = (*s).getPosition().y;
			(*s).move(0, predkosc);
			(*s1).move(0, predkosc);
			a++;
			_skokZegar.restart();
			if (predkosc == predPocz)
			{
				skacze = 0;
			}
			return true;
		}
		if (skacze == 0)
		{
			return false;
		}
	}

	//////////////////////////// KOLIZJA /////////////////////////////////////////////////////////
	bool MenadzerWejscia::Kolizja(Sprite sprite1, Sprite sprite2)
	{
		IntRect s1(sprite1.getPosition().x, sprite1.getPosition().y, sprite1.getGlobalBounds().width, sprite1.getGlobalBounds().height);
		IntRect s2(sprite2.getPosition().x, sprite2.getPosition().y, sprite2.getGlobalBounds().width, sprite2.getGlobalBounds().height);
		if (s1.intersects(s2))
		{
			return true;
		}
		else
			return false;
	}

	bool MenadzerWejscia::Kolizja(Sprite sprite1, CircleShape kolo)
	{
		IntRect s1(sprite1.getPosition().x, sprite1.getPosition().y, sprite1.getGlobalBounds().width, sprite1.getGlobalBounds().height);
		IntRect s2(kolo.getPosition().x, kolo.getPosition().y, kolo.getGlobalBounds().width, kolo.getGlobalBounds().height);
		if (s1.intersects(s2))
		{
			return true;
		}
		else
			return false;
	}

	bool MenadzerWejscia::Kolizja(Sprite sprite1, RectangleShape pros)
	{
		IntRect s1(sprite1.getPosition().x, sprite1.getPosition().y, sprite1.getGlobalBounds().width, sprite1.getGlobalBounds().height);
		IntRect s2(pros.getPosition().x, pros.getPosition().y, pros.getGlobalBounds().width, pros.getGlobalBounds().height);
		if (s1.intersects(s2))
		{
			return true;
		}
		else
			return false;
	}

	//////////////////////////// ZMIENNE MIÊDZYPLIKOWE /////////////////////////////////////////////////////////
	Trudnosc MenadzerWejscia::poziomGet()
	{
		return poziom;
	}
	void MenadzerWejscia::poziomSet(Trudnosc poziom)
	{
		this->poziom = poziom;
	}

	int MenadzerWejscia::punktyGet()
	{
		return punkty;
	}
	void MenadzerWejscia::punktySet(int punkty)
	{
		this->punkty = punkty;
	}

	int MenadzerWejscia::znacznikPunktyGet()
	{
		return znacznikPunkty;
	}
	void MenadzerWejscia::znacznikPunktySet(int znacznikPunkty)
	{
		this->znacznikPunkty = znacznikPunkty;
	}

	int MenadzerWejscia::hpGet()
	{
		return hp;
	}
	void MenadzerWejscia::hpSet(int hp)
	{
		this->hp = hp;
	}

	//////////////////////////// ZAPIS I ODCZYT /////////////////////////////////////////////////////////
	void MenadzerWejscia::zapis(const char* nazwa, const char* tryb, int punkty)
	{
		FILE* plik;
		if ((plik = fopen(nazwa, tryb)) == NULL)
		{
			exit(0);
		}
		fwrite(&punkty, sizeof(int), 1, plik);
		fclose(plik);
	}

	void MenadzerWejscia::zapisGry(const char* nazwa, int punkty, int znacznikPunkty, int hp, int poziom)
	{
		zapis(nazwa, "w+b", 1);
		zapis(nazwa, "a+b", punkty);
		zapis(nazwa, "a+b", znacznikPunkty);
		zapis(nazwa, "a+b", hp);
		zapis(nazwa, "a+b", poziom);
	}

	void MenadzerWejscia::odczytPocz(const char* nazwa)
	{
		FILE* plik;
		if ((plik = fopen(nazwa, "r+b")) == NULL)
		{
			int buf = 0;
			for (int i = 0; i < 5; i++)
				zapis(nazwa, "a+b", buf);
		}
		else
			fclose(plik);
	}

	void MenadzerWejscia::zapisUsun(const char* nazwa)
	{
		FILE* plik;
		if ((plik = fopen(nazwa, "r+b")) == NULL)
		{
			exit(0);
		}
		zapis(nazwa, "w+b", 0);
		for (int i = 0; i < 4; i++)
			zapis(nazwa, "a+b", 0);
	}

	void MenadzerWejscia::odczyt(const char* nazwa, int rozmiar, int* zmienna)
	{
		FILE* plik;
		int buf;
		if ((plik = fopen(nazwa, "r+b")) == NULL)
		{
			exit(0);
		}
		for (int i = 0; i < rozmiar; i++)
		{
			fread(&buf, sizeof(int), 1, plik);
			*(zmienna + i) = buf;
		}
		fclose(plik);
	}

	void MenadzerWejscia::sortuj(int tab[], int n)
	{
		for (int i = 0; i < n; i++)
			for (int j = 1; j < n - i; j++) 
				if (tab[j - 1] > tab[j])
				{
					int buf = tab[j-1];
					tab[j - 1] = tab[j];
					tab[j] = buf;
				}
	}

	void MenadzerWejscia::zapisPunkty(const char* nazwa, int punkty)
	{
		int istnieje = false;
		int buf[6];
		buf[5] = punkty;
		odczyt(nazwa, 5, buf);
		for (int i = 0; i < 5; i++)
			if (buf[i] == buf[5])
				istnieje = true;
		if (istnieje == false)
		{
			sortuj(buf, 6);
			zapis(nazwa, "w+b", buf[5]);
			for (int i = 4; i > 0; i--)
				zapis(nazwa, "a+b", buf[i]);
		}
	}
}
