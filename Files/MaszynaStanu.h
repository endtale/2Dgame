#pragma once

#include <memory>
#include <stack>
#include "Stan.h"

using namespace std;

namespace Moje
{
	typedef unique_ptr<Stan> SR; // unikalny wska�nik na klase g��wn�

	class MaszynaStanu
	{
	public:
		~MaszynaStanu() {}

		void DodajStan(SR nowyStan, bool wymieniany = true);
		void UsunStan();
		void ProcesZmianStanu();

		SR &GetActiveState();

	private:
		stack<SR> _stany; // wymienia zawarto�� stacku (std)
		SR _nowyStan;

		bool _usuwany;
		bool _dodawany;
		bool _wymieniany;
	};
}
