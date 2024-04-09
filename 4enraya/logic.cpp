#define LIMITEI 7
#define LIMITEJ 7
#define ZERO 0
#include <iostream>
#include "tabla.h"

short posUSER = 0;
char pieza = 'O';
short posCAIDA;

void gameplay(char* tabla, char table[LIMITEI][LIMITEJ])
{
	bool tirar = false;
	for (short i = 1; i <= 2; i++)
	{
		if (i == 1)
		{
			std::cout << "Turno del jugador 1" << std::endl;
			pieza = 'O';
		}
		else if(i == 2)
		{
			std::cout << "Turno del jugador 2" << std::endl;
			pieza = 'X';
		}
		while (!tirar)
		{
			std::cout << "Donde quieres tirar tu ficha: ";
			std::cin >> posUSER;

			if (posUSER >= 1 && posUSER < 7)
			{
				tirar = true;
			}
			else
			{
				std::cout << "No puedes tirar la ficha ahi" << std::endl;
			}
		}
		tirar = false;
		posUSER = posUSER - 1;
		for (short i = ZERO; i < LIMITEI; i++)
		{
			std::cout << i;

			if (table[posUSER][i] != '*')
			{
				posCAIDA = i;
			}
		}

		posCAIDA = posCAIDA - 1;
		std::cout << posCAIDA;
		tabla[posCAIDA * LIMITEI + posUSER] = pieza;
	}
}
