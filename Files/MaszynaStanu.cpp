#include "MaszynaStanu.h"

using namespace std;

namespace Moje
{
	void MaszynaStanu::DodajStan(SR nowyStan, bool wymieniany)
	{
		this->_dodawany = true;
		this->_wymieniany = wymieniany;
		this->_nowyStan = move(nowyStan); // (std)
	}

///////////////////////////////////////////////////////////////////

	void MaszynaStanu::UsunStan()
	{
		this->_wymieniany = true;
	}

///////////////////////////////////////////////////////////////////

	void MaszynaStanu::ProcesZmianStanu()
	{
		if (this->_usuwany && !this->_stany.empty())
		{
			this->_stany.pop();

			if (!this->_stany.empty())
			{
				this->_stany.top()->Wznow();
			}

			this->_usuwany = false;
		}

		if (this->_dodawany)
		{
			if (!this->_stany.empty())
			{
				if (this->_wymieniany)
				{
					this->_stany.pop();
				}
				else
				{
					this->_stany.top()->Pauza();
				}
			}

			this->_stany.push(move(this->_nowyStan));
			this->_stany.top()->Inicjalizacja();
			this->_dodawany = false;
		}
	}

///////////////////////////////////////////////////////////////////

	SR &MaszynaStanu::GetActiveState()
	{
		return this->_stany.top();
	}
}