/*
																   .---.
																  /  .  \
																 |\_/|   |
																 |   |  /|
	  .----------------------------------------------------------------' |
	 /  .-.                                                              |
	|  /   \       Programa creado por Carlos Aguilar                    |
	| |\_.  |                                                            |
	|\|  | /|                      El                                    |
	| `---' |                                                            |
	|       |                   9 / 11 / 2012                            |
	|       |                                                           /
	|       |----------------------------------------------------------'
	\       |
	 \     /
	  `---'

*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
using namespace std;

char simon_says();
void simon_color(char);
void welcome();

int main()
{
	int turn(1), count(0);
	char simon[200], player;

	system("color 0A");
	
	welcome();

	cout << "\n\n\t\tSimon Says !\n"
		 << "\n============\n\n"
		 << "Rules:\n"
		 << "Simon will pick a random color each turn.\n"
		 << "You must remember the full color combination\n"
		 << "and repeat it by typing it. There are 3 colors:\n"
		 << "\tRed ===> R\n\tGreen ===> G\n\tBlue ===> B\n\tYellow ===> Y\n\n"
		 << "---------------------------------------------\n\n"
		 << "Type 'E' to exit whenever you want to.\n\n";
	system("pause");
	system("cls");

	for(int x = 1; x <= 200; x++)
	{
		if(turn == 1)
		{
			cout << "\n\tSimon's Turn:\n\n";

			simon[count] = simon_says();

			for(int y = 0; y <= count; y++)
			{
				Sleep(500);
				simon_color(simon[y]);
				Sleep(1500);
				system("color 0A");
			}

			Sleep(500);
			turn = 2;
			system("cls");
		}
		else
		{
			cout << "\n\tYour Turn:\n\n";

			for(int z = 0; z <= count; z++)
			{
				cin >> player;

				while(player != 'R' && player != 'G' && player != 'B' && player != 'Y' && player != 'E')
				{
					cout << "\nError: Invalid color.\nTry again.\n";
					cin >> player;
				}
				
				if(player == 'E')
				{
					system("cls");
					system("color 0A");
					cout << "\n\tThanks for playing !!!\n\n";
					system("pause");
					return 0;
				}

				if(player != simon[z])
				{
					simon_color(simon[z]);
					cout << "\nThe corrrect answer was: " << simon[z] << endl
						 << "GAME OVER\n\n";
					system("pause");
					return 0;
				}

				simon_color(player);
				Sleep(500);
				system("color 0A");
			}

			count++;
			turn = 1;
			cout << "\nWell Done !!!";
			Sleep(1000);
			system("color 0A");
			system("cls");
		}
	}

	return 0;
}

//==========================================================
//
//	Says a random color

char simon_says()
{
	int random;

	srand(time(NULL));

	random = rand() % 4;

	if(random == 0)
	{
		return 'R';
	} else if(random == 1)
	{
		return 'G';
	} else if(random == 2)
	{
		return 'B';
	} else
	{
		return 'Y';
	}
}

//==========================================================
//
//	Paints Screen

void simon_color(char color)
{
	if(color == 'R')
	{
		system("color C0");
	} else if(color == 'G')
	{
		system("color A0");
	} else if(color == 'B')
	{
		system("color 30");
	} else
	{
		system("color 60");
	}
}

//==========================================================
//
//	Welcome

void welcome()
{
	system("cls");
	cout << endl
		 << "\t _ _ _\n"
		 << "\t| | | |\n"
		 << "\t| | | |\n"
		 << "\t|_____|";
	Sleep(500);
	system("cls");
	cout << endl
		 << "\t _ _ _\n"
		 << "\t| | | |___\n"
		 << "\t| | | | -_|\n"
		 << "\t|_____|___|";
	Sleep(500);
	system("cls");
	cout << endl
		 << "\t _ _ _     _\n"
		 << "\t| | | |___| |\n"
		 << "\t| | | | -_| |\n"
		 << "\t|_____|___|_|";
	Sleep(500);
	system("cls");
	cout << endl
		 << "\t _ _ _     _\n"
		 << "\t| | | |___| |___\n"
		 << "\t| | | | -_| |  _|\n"
		 << "\t|_____|___|_|___|";
	Sleep(500);
	system("cls");
	cout << endl
		 << "\t _ _ _     _\n"
		 << "\t| | | |___| |___ ___\n"
		 << "\t| | | | -_| |  _| . |\n"
		 << "\t|_____|___|_|___|___|";
	Sleep(500);
	system("cls");
	cout << endl
		 << "\t _ _ _     _\n"
		 << "\t| | | |___| |___ ___ _____\n"
		 << "\t| | | | -_| |  _| . |     |\n"
		 << "\t|_____|___|_|___|___|_|_|_|";
	Sleep(500);
	system("cls");
	cout << endl
		 << "\t _ _ _     _\n"
		 << "\t| | | |___| |___ ___ _____ ___\n"
		 << "\t| | | | -_| |  _| . |     | -_|\n"
		 << "\t|_____|___|_|___|___|_|_|_|___|";
	Sleep(2000);
}