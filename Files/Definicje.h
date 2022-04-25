#pragma once

//ustawienia gry

#define SZER_OKNA 800
#define WYS_OKNA 500
#define TYTUL "Smykosz"

#define LOGO_CZAS 2.0
#define LOGO_LOKALIZACJA "Resources/logo.png"

#define SZYBKOSC_PORUSZANIA 4.0f
#define SZYBKOSC_PORUSZANIA_ELEMENTY 4.0f
#define GRAWITACJA 5.0f
#define TYL_MAPY -350.0f //tylna rura resp
#define RESPAWN 300 //moby

#define WYS_ZIEMI 70
#define CZAS_GRACZ_KLATKA 150.0f

#define CZCIONKA_ROZMIAR 25
#define CZCIONKA_GRUBOSC 2
#define CZCIONKA_SPACING 3

//resources

#define MENU_TLO_LOKALIZACJA "Resources/Tlo.png"
#define GRA_TLO_LOKALIZACJA "Resources/Tlo.png"
#define ZAPISY_TLO_LOKALIZACJA "Resources/Tlo.png"
#define WYNIKI_TLO_LOKALIZACJA "Resources/Tlo.png"
#define KONIECGRY_TLO_LOKALIZACJA "Resources/Tlo.png"

#define MENU_TYTUL_LOKALIZACJA "Resources/menuTytul.png"
#define MENU_GRAJ_LOKALIZACJA "Resources/menuGraj.png"
#define MENU_GRAJ_NACISNIETY_LOKALIZACJA "Resources/menuGrajNacisniety.png"
#define MENU_ZAPISZ_LOKALIZACJA "Resources/zapisz.png"
#define MENU_ZAPISZ_NACISNIETY_LOKALIZACJA "Resources/zapiszNacisniety.png"
#define MENU_WYNIKI_LOKALIZACJA "Resources/wyniki.png"
#define MENU_WYNIKI_NACISNIETY_LOKALIZACJA "Resources/wynikiNacisniety.png"

#define POWROT_LOKALIZACJA "Resources/powrot.png"
#define POWROT_NACISNIETY_LOKALIZACJA "Resources/powrotNacisniety.png"

#define GAMEOVER_LOKALIZACJA "Resources/gameover.png"

#define ZIEMIA_LOKALIZACJA "Resources/ziemia.png"
#define RURA_LOKALIZACJA "Resources/rura.png"
#define CHMURY_LOKALIZACJA "Resources/chmury.png"

#define GRACZSTOI_1_LOKALIZACJA "Resources/gracz/graczstoi1.png"
#define GRACZSTOI_2_LOKALIZACJA "Resources/gracz/graczstoi2.png"
#define GRACZSTOI_3_LOKALIZACJA "Resources/gracz/graczstoi3.png"
#define GRACZSTOI_4_LOKALIZACJA "Resources/gracz/graczstoi4.png"
#define GRACZBIEGNIE_1_LOKALIZACJA "Resources/gracz/graczbiegnie1.png"
#define GRACZBIEGNIE_2_LOKALIZACJA "Resources/gracz/graczbiegnie2.png"
#define GRACZBIEGNIE_3_LOKALIZACJA "Resources/gracz/graczbiegnie3.png"
#define GRACZBIEGNIE_4_LOKALIZACJA "Resources/gracz/graczbiegnie4.png"
#define GRACZBIEGNIE_5_LOKALIZACJA "Resources/gracz/graczbiegnie5.png"
#define GRACZBIEGNIE_6_LOKALIZACJA "Resources/gracz/graczbiegnie6.png"
#define GRACZSKACZE_LOKALIZACJA "Resources/gracz/graczskacze1.png"

#define GLUT_1_LOKALIZACJA "Resources/Glut/Glut1.png"
#define GLUT_2_LOKALIZACJA "Resources/Glut/Glut2.png"
#define GLUT_3_LOKALIZACJA "Resources/Glut/Glut3.png"
#define GLUT_4_LOKALIZACJA "Resources/Glut/Glut4.png"
#define GLUT_OBRAZENIA_LOKALIZACJA "Resources/Glut/GlutObrazenia.png"

#define KAKTUS_LOKALIZACJA "Resources/kaktus.png"

#define MAG_1_LOKALIZACJA	"Resources/Mag/Mag1.png"
#define MAG_2_LOKALIZACJA	"Resources/Mag/Mag2.png"
#define MAG_3_LOKALIZACJA	"Resources/Mag/Mag3.png"
#define MAG_4_LOKALIZACJA	"Resources/Mag/Mag4.png"
#define MAG_5_LOKALIZACJA	"Resources/Mag/Mag5.png"
#define MAG_RANNY_LOKALIZACJA	"Resources/Mag/MagRanny.png"

#define CZCIONKA_LOKALIZACJA "Resources/Czcionka/arial.ttf"

#define MENU_GRA_LOKALIZACJA "Resources/RozgrywkaMenu.png"
#define OKNO "Resources/OknoMale.png"
#define STEROWANIE_LOKALIZACJA "Resources/sterowanie.png"
#define PUNKTACJA_LOKALIZACJA "Resources/punktacja.png"
#define ZAPISY_LOKALIZACJA "Resources/zapisy.png"
#define WYJSCIE_1_LOKALIZACJA "Resources/wyjscie1.png"
#define WYJSCIE_2_LOKALIZACJA "Resources/wyjscie2.png"

//funkcje wyliczaniowe

enum Rozgrywka //stan rozgrywki
{
	Esc,
	Pomoc,
	Plaing,
	GameOver
};

enum Trudnosc //poziomy trudnosci
{
	Latwy,
	Sredni,
	Trudny,
};


