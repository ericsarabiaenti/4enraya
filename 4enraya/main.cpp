#define LIMITEI 7
#define LIMITEJ 7

#include <iostream>
#include "tabla.h"
#include "logic.h"

void main()
{
	char tabla[LIMITEI][LIMITEJ];
	bool GAMEOVER = false;

	createTable(tabla[0]);
	showTable(tabla);

	while (!GAMEOVER)
	{
		gameplay(tabla[0], tabla);
		showTable(tabla);
	}
}