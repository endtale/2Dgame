#include "HUD.h"

namespace Moje
{
	HUD::HUD(DG dane) : _dane(dane)
	{
		_punktyTekst.setFont(_dane->aktyw.GetFont("Arial"));
		_punktyTekst.setCharacterSize(CZCIONKA_ROZMIAR);
		_punktyTekst.setFillColor(Color::Red);
		_punktyTekst.setOutlineThickness(CZCIONKA_GRUBOSC);
		_punktyTekst.setLetterSpacing(CZCIONKA_SPACING);
		_punktyTekst.setPosition(50, WYS_OKNA - WYS_ZIEMI + WYS_ZIEMI/2.5);

		_hpTekst.setFont(_dane->aktyw.GetFont("Arial"));
		_hpTekst.setCharacterSize(CZCIONKA_ROZMIAR);
		_hpTekst.setFillColor(Color::Red);
		_hpTekst.setOutlineThickness(CZCIONKA_GRUBOSC);
		_hpTekst.setLetterSpacing(CZCIONKA_SPACING);
		_hpTekst.setPosition(SZER_OKNA - 150, WYS_OKNA - WYS_ZIEMI + WYS_ZIEMI / 2.5);

		_pomoc.setFont(_dane->aktyw.GetFont("Arial"));
		_pomoc.setString("F1 - Pomoc");
		_pomoc.setCharacterSize(CZCIONKA_ROZMIAR / 1.5);
		_pomoc.setFillColor(Color::Red);
		_pomoc.setOutlineThickness(CZCIONKA_GRUBOSC / 2);
		_pomoc.setLetterSpacing(CZCIONKA_SPACING);
		_pomoc.setOrigin(_pomoc.getGlobalBounds().width / 2, 0);
		_pomoc.setPosition(SZER_OKNA / 2, WYS_OKNA - WYS_ZIEMI + 2 * (WYS_ZIEMI / 3));

		_menu.setFont(_dane->aktyw.GetFont("Arial"));
		_menu.setString("Esc - Menu");
		_menu.setCharacterSize(CZCIONKA_ROZMIAR / 1.5);
		_menu.setFillColor(Color::Red);
		_menu.setOutlineThickness(CZCIONKA_GRUBOSC / 2);
		_menu.setLetterSpacing(CZCIONKA_SPACING);
		_menu.setOrigin(_menu.getGlobalBounds().width / 2, 0);
		_menu.setPosition(SZER_OKNA / 2, WYS_OKNA - WYS_ZIEMI + WYS_ZIEMI / 3);
	}

	void HUD::rysujHUD()
	{
		_dane->okno.draw(_punktyTekst);
		_dane->okno.draw(_hpTekst);
		_dane->okno.draw(_pomoc);
		_dane->okno.draw(_menu);
	}

	void HUD::aktualizujPunkty(int punkty, int hp)
	{
		String P1 = "Punkty: ";
		String P2 = to_string(punkty);
		_punktyTekst.setString(P1 + P2);

		String P3 = "HP: ";
		String P4 = to_string(hp);
		_hpTekst.setString(P3 + P4);
	}
}
