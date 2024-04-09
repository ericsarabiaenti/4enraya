#define LIMITEI 7
#define LIMITEJ 7
#define ZERO 0
#include <iostream>
#include "tabla.h"
short posUSER = 0;
char pieza = 'O';
void ganador(char tabla[LIMITEI][LIMITEJ], bool* GAMEOVER)
{
	short contador = 0;
	for (short i = ZERO; i < LIMITEI; i++)
	{
		for (short j = ZERO; j < LIMITEJ; j++)
		{
			if (tabla[i][j] == 'O' && tabla[i + 1][j] == 'O' && tabla[i + 2][j] == 'O' && tabla[i + 3][j] == 'O')
			{
				std::cout << "GANA EL JUGADOR 1";
				*GAMEOVER = true;

			}
			if (tabla[i][j] == 'X' && tabla[i + 1][j] == 'X' && tabla[i + 2][j] == 'X' && tabla[i + 3][j] == 'X')
			{
				std::cout << "GANA EL JUGADOR 2";
				*GAMEOVER = true;
			}
			if (tabla[i][j] == 'O' && tabla[i][j + 1] == 'O' && tabla[i][j + 2] == 'O' && tabla[i][j + 3] == 'O')
			{
				std::cout << "GANA EL JUGADOR 1";
				*GAMEOVER = true;
			}
			if (tabla[i][j] == 'X' && tabla[i][j + 1] == 'X' && tabla[i][j + 2] == 'X' && tabla[i][j + 3] == 'X')
			{
				std::cout << "GANA EL JUGADOR 2";
				*GAMEOVER = true;
			}
			if (tabla[i][j] == 'O' && tabla[i + 1][j + 1] == 'O' && tabla[i + 2][j + 2] == 'O' && tabla[i + 3][j + 3] == 'O')
			{
				std::cout << "GANA EL JUGADOR 1";
				*GAMEOVER = true;
			}
			if (tabla[i][j] == 'X' && tabla[i + 1][j + 1] == 'X' && tabla[i + 2][j + 2] == 'X' && tabla[i + 3][j + 3] == 'X')
			{
				std::cout << "GANA EL JUGADOR 1";
				*GAMEOVER = true;
			}
		}
	}
}
void gameplay(char* tabla, char table[LIMITEI][LIMITEJ])
{
	bool tirar = false;
	bool GAMEOVER = false;
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

			if (posUSER >= 1 && posUSER <= 7)
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
			if (table[i][posUSER] != '*')
			{
				tabla[(i - 1) * LIMITEI + posUSER] = pieza;
				i = LIMITEI;
			}
		}
		showTable(table);
		ganador(table, &GAMEOVER);
		if (GAMEOVER == true)
		{
			i = 3;
		}
		std::cout << std::endl;

	}
}