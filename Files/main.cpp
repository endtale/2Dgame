#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Pêtla.h"
#include "Definicje.h"

int main()
{
	srand(time(NULL));
	Moje::Gra(SZER_OKNA, WYS_OKNA, TYTUL);
}