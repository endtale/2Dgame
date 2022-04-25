#include "StanGry.h"
#include "StanPrzegrana.h"
#include "Definicje.h"
#include <sstream>
#include <iostream>

namespace Moje
{
	StanGry::StanGry(DG dane) :_dane(dane)
	{

	}

	void StanGry::Inicjalizacja()
	{
		rozgrywka = Plaing;

		znacznik = 0;
		znacznikMag = 2;
		znacznikGlut = 1;
		znacznikHp = true;

		_punkty = _dane->wejscie.punktyGet();
		znacznikPunkty = _dane->wejscie.znacznikPunktyGet();
		_hp = _dane->wejscie.hpGet();
		poziom = _dane->wejscie.poziomGet();

		if (poziom == Latwy)
		{
			_maxHp = 10;
			poziomInt = 1;
		}
		if (poziom == Sredni)
		{
			_maxHp = 6;
			poziomInt = 2;
		}
		if (poziom == Trudny)
		{
			_maxHp = 4;
			poziomInt = 3;

		}

		_dane->aktyw.ladujTeksture("Ziemia", ZIEMIA_LOKALIZACJA);

		_dane->aktyw.ladujTeksture("Kaktus", KAKTUS_LOKALIZACJA);

		_dane->aktyw.ladujTeksture("Glut1", GLUT_1_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Glut2", GLUT_2_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Glut3", GLUT_3_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Glut4", GLUT_4_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("GlutObrazenia", GLUT_OBRAZENIA_LOKALIZACJA);

		_dane->aktyw.ladujTeksture("Mag1", MAG_1_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Mag2", MAG_2_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Mag3", MAG_3_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Mag4", MAG_4_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Mag5", MAG_5_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("MagRanny", MAG_RANNY_LOKALIZACJA);

		_dane->aktyw.ladujTeksture("MenuTlo", MENU_GRA_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Okno", OKNO);
		_dane->aktyw.ladujTeksture("Sterowanie", STEROWANIE_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Punktacja", PUNKTACJA_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Zapisy", ZAPISY_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Wyjscie1", WYJSCIE_1_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Wyjscie2", WYJSCIE_2_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Powrot", POWROT_LOKALIZACJA);
		_dane->aktyw.ladujTeksture("Powrot Nacisniety", POWROT_NACISNIETY_LOKALIZACJA);

		_dane->aktyw.ladujCzcionke("Arial", CZCIONKA_LOKALIZACJA);

		ziemia = new Ziemia(_dane);
		chmury = new Chmury(_dane);
		gracz = new Gracz(_dane);
		rura = new Rura(_dane);
		
		glut = new Glut(_dane);
		kaktus = new Kaktus(_dane);
		mag = new Mag(_dane);

		pocisk = new Pocisk(_dane);
		
		punktySprite = new SpritePunkty(_dane);
		hud = new HUD(_dane);

		menu = new MenuRozgrywka(_dane);
		pomoc = new PomocRozgrywka(_dane);

		_dane->aktyw.ladujTeksture("Gra Tlo", GRA_TLO_LOKALIZACJA);
		_tlo.setTexture(this->_dane->aktyw.GetTexture("Gra Tlo"));
	}

	void StanGry::kolizja()
	{
		for (int i = 0; i < kaktus->kolizja().size(); i++)
			if ((_dane->wejscie.Kolizja(gracz->kolizja(), kaktus->kolizja().at(i))) == true)
				rozgrywka = GameOver;
		
		for (int i = 0; i < kaktus->kolizja().size(); i++)
			if ((_dane->wejscie.Kolizja(gracz->kolizja(), glut->kolizja().at(i))) == true)
				rozgrywka = GameOver;
		
		for (int i = 0; i < mag->kolizja().size(); i++)
			if ((_dane->wejscie.Kolizja(gracz->kolizja(), mag->kolizja().at(i))) == true)
				rozgrywka = GameOver;
		
		for (int i = 0; i < mag->kolizjaPociski().size(); i++)
			if ((_dane->wejscie.Kolizja(gracz->kolizja(), mag->kolizjaPociski().at(i))) == true)
				rozgrywka = GameOver;

		for (int i = 0; i < mag->kolizja().size(); i++)
			for (int j = 0; j < pocisk->kolizja().size(); j++)
				if ((_dane->wejscie.Kolizja(mag->kolizja2().at(i), pocisk->kolizja().at(j))) == true)
				{
					mag->magObrazenia(true);
					if (_hp < _maxHp)
						_hp++;
					_punkty += 2;
					znacznikPunkty += 2;
					mag->kolizjaPomoc(pocisk->kolizja().at(j));
				}

		for (int i = 0; i < mag->kolizja().size(); i++)
			for (int j = 0; j < pocisk->kolizja().size(); j++)
				if ((_dane->wejscie.Kolizja(mag->kolizja().at(i), pocisk->kolizja().at(j))) == true)
					pocisk->pociskUsun(mag->kolizja().at(i));

		for (int i = 0; i < glut->kolizja().size(); i++)
			for (int j = 0; j < pocisk->kolizja().size(); j++)
				if ((_dane->wejscie.Kolizja(glut->kolizja2().at(i), pocisk->kolizja().at(j))) == true)
				{
					glut->obrazenia.at(i) = true;
					if (_hp < _maxHp)
						_hp++;
					_punkty++;
					znacznikPunkty++;
					glut->kolizjaPomoc(pocisk->kolizja().at(j));
				}

		for (int i = 0; i < glut->kolizja().size(); i++)
			for (int j = 0; j < pocisk->kolizja().size(); j++)
				if ((_dane->wejscie.Kolizja(glut->kolizja().at(i), pocisk->kolizja().at(j))) == true)
					pocisk->pociskUsun(glut->kolizja().at(i));


		for (int i = 0; i < punktySprite->kolizja().size(); i++)
			if (_dane->wejscie.Kolizja(gracz->kolizja(), punktySprite->kolizja().at(i)))
			{
				_punkty++;
				znacznikPunkty++;
				if (_hp < _maxHp)
					_hp++;
			}
	}

	void StanGry::hp()
	{
		if (_zegarHp.getElapsedTime().asSeconds() > 2)
		{
			znacznikHp = false;
			_zegarHp.restart();
		}

		if (_hp == 0)
			rozgrywka = GameOver;

		if (_zegarHp.getElapsedTime().asSeconds() > 1.35 && znacznikHp == false)
		{
			_hp--;
			_zegarHp.restart();
		}

		if (znacznikPunkty == 10)
		{
			if (_hp <= _maxHp - 2)
				_hp += 2;
			else
				_hp = _maxHp;

			znacznikPunkty = 0;
		}
	}

	bool StanGry::czyZapisMozliwy()
	{
		if (rura->kolizja().getPosition().x + rura->kolizja().getGlobalBounds().width > 0 &&
			gracz->kolizja().getPosition().y + gracz->kolizja().getGlobalBounds().height > WYS_OKNA - WYS_ZIEMI - 1)
			return true;
		else
			return false;
	}

	void StanGry::OgarnijWejscie()
	{
		Event event;

		while (_dane->okno.pollEvent(event))
		{	
			if (Event::Closed == event.type)
			{
				_dane->okno.close();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape) && rozgrywka != Pomoc)
		{
			rozgrywka = Esc;
		}
		if (Keyboard::isKeyPressed(Keyboard::F1) && rozgrywka != Esc)
		{
			rozgrywka = Pomoc;
		}
		if (Keyboard::isKeyPressed(Keyboard::Enter) && menu->wyborGet() == 1 )
		{
			rozgrywka = Plaing;
		}
		if (Keyboard::isKeyPressed(Keyboard::Enter) && menu->wyborGet() == 2)
		{
			menu->akcjaSet(true);
			menu->zapisSet(czyZapisMozliwy());
		}
		if (Keyboard::isKeyPressed(Keyboard::Enter) && menu->wyborGet() == 3)
		{
			_dane->maszyna.DodajStan(SR(new MenuGlowne(_dane)), true);
		}
		if (Keyboard::isKeyPressed(Keyboard::Enter) && menu->wyborGet() == 4)
		{
			exit(0);
		}

		if (menu->zapisZnacznikGet() == 1)
			_dane->wejscie.zapisGry("Zapis1.dat", _punkty, znacznikPunkty, _hp, poziomInt);
		if (menu->zapisZnacznikGet() == 2)
			_dane->wejscie.zapisGry("Zapis2.dat", _punkty, znacznikPunkty, _hp, poziomInt);
		if (menu->zapisZnacznikGet() == 3)
			_dane->wejscie.zapisGry("Zapis3.dat", _punkty, znacznikPunkty, _hp, poziomInt);
	}

	void StanGry::Aktualizuj(float delta)
	{
		if (pomoc->wyjscieGet() == true)
		{
			rozgrywka = Plaing;
			pomoc->wyjscieSet(false);
		}

		if (rozgrywka == GameOver)
		{
				if (poziom == Latwy)
					_dane->wejscie.zapisPunkty("wynikiLatwy.dat", _punkty);
				if (poziom == Sredni)
					_dane->wejscie.zapisPunkty("wynikiSredni.dat", _punkty);
				if (poziom == Trudny)
					_dane->wejscie.zapisPunkty("wynikiTrudny.dat", _punkty);
			_dane->wejscie.punktySet(_punkty);
			_dane->maszyna.DodajStan(SR(new Przegrana(_dane)), true);
		}
				
		if (rozgrywka == Plaing)
		{
			if ((_dane->wejscie.Kolizja(gracz->kolizja(), rura->kolizja())) == false)
			{
				ziemia->ZiemiaAnimuj();
				rura->RuraAnimuj();
				glut->GlutRuch();
				mag->MagRuch();
				kaktus->RuchKaktus();
				punktySprite->ruchPunkt(gracz->kolizja());
				(chmury->_kolizja) = false;
			}
			if ((_dane->wejscie.Kolizja(gracz->kolizja(), rura->kolizja())) == true && (Keyboard::isKeyPressed(Keyboard::Left)))
			{
				(chmury->_kolizja) = true;
			}
			if ((_dane->wejscie.Kolizja(gracz->kolizja(), rura->kolizja())) == true && (Keyboard::isKeyPressed(Keyboard::Right)))
			{
				ziemia->ZiemiaAnimuj();
				rura->RuraAnimuj();
				(chmury->_kolizja) = false;
			}

			pocisk->pociskAnimuj(6, 10, 20, gracz->kolizja().getPosition().x + gracz->kolizja().getGlobalBounds().width / 2,
				gracz->kolizja().getPosition().y + gracz->kolizja().getGlobalBounds().height / 2.4, Color::Cyan, true, 0.5, Keyboard::K);

			mag->MagAnimuj();
			glut->GlutAnimuj();
			chmury->ChmuryAnimuj();
			gracz->GraczAnimuj();
			hud->aktualizujPunkty(_punkty, _hp);

			if ((znacznik == 0 && _resp.getElapsedTime().asSeconds() > 2) || (znacznik == 1 && mag->kolizja().back().getPosition().x < RESPAWN) ||
				(znacznik == 2 && kaktus->kolizja().back().getPosition().x < RESPAWN) ||
				(znacznik == 3 && glut->kolizja().back().getPosition().x < RESPAWN))
			{
				mob = rand() % 300 + 1;

				if (mob > 100 && mob <= 200)
				{
					glut->SpawnPomocniczy();
					kaktus->SpawnKaktus(SZER_OKNA);
					punktySprite->spawnPunkt(SZER_OKNA + 25);

					znacznik = 2;
					if (znacznikMag < 2)
						znacznikMag++;
					if (znacznikGlut < 1)
						znacznikGlut++;
				}
				else if ((mob <= 100) && (znacznikMag == 2))
				{
					kaktus->SpawnPomocniczy();//bez tego siê sypie
					glut->SpawnPomocniczy();
					mag->SpawnMag();
					punktySprite->spawnPunkt(SZER_OKNA + 36);

					znacznik = 1;
					znacznikMag = 0;
					if (znacznikGlut < 1)
						znacznikGlut++;
				}
				else if ((mob > 200) && (znacznikGlut == 1))
				{
					kaktus->SpawnPomocniczy();
					glut->SpawnGlut();
					punktySprite->spawnPunkt(SZER_OKNA + 35);

					znacznikGlut = 0;
					znacznik = 3;
					if (znacznikMag < 2)
						znacznikMag++;
				}
			}

			hp();
			kolizja();
		}

		if (rozgrywka == Esc)
		{
			menu->aktualizuj();
		}

		if (rozgrywka == Pomoc)
		{
			pomoc->aktualizuj();
		}
	}

	void StanGry::Rysuj(float delta)
	{
		_dane->okno.clear();
		_dane->okno.draw(_tlo);

		pocisk->pociskRysuj();
		mag->MagRysuj();
		glut->GlutRysuj();
		kaktus->RysujKaktus();
		rura->RuraRysuj();
		ziemia->ZiemiaRysuj();
		chmury->ChmuryRysuj();
		gracz->GraczRysyj();

		if (rozgrywka == Plaing)
			hud->rysujHUD();

		if (rozgrywka == Esc)
		{
			menu->rysujMenu();
		}

		if (rozgrywka == Pomoc)
		{
			pomoc->rysujPomoc();
		}

		_dane->okno.display();
	}
}

