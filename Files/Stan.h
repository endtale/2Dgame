#pragma once

namespace Moje
{
	class Stan
	{
	public:
		virtual void Inicjalizacja() = 0;

		virtual void OgarnijWejscie() = 0;
		virtual void Aktualizuj(float delta) = 0;
		virtual void Rysuj(float delta) = 0;

		virtual void Pauza() {}
		virtual void Wznow() {}
	};
}

