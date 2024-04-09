#define LIMITEI 7
#define LIMITEJ 7
#define ZERO 0
#include <iostream>

void createTable(char* tabla)
{
	char I = '1';
	for (short i = ZERO; i < LIMITEI; i++)
	{
		for (short j = ZERO; j < LIMITEJ; j++)
		{
			tabla[i * LIMITEJ + j] = '*';

			if (i == 6)
			{
				tabla[i * LIMITEJ + j] = I;
				I++;
			}
		}
	}
}

void showTable(char tabla[LIMITEI][LIMITEJ])
{
	for (short i = ZERO; i < LIMITEI; i++)
	{
		for (short j = ZERO; j < LIMITEJ; j++)
		{
			std::cout << tabla[i][j] << " ";
		}
		std::cout << std::endl;
	}
}