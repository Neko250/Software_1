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

const char beep = 7;

void language(int&);
void welcome(int);
void rules(int);
void lets_play(int);
void difficulty(int, int&, int&);
void simons_turn(int, int&, int, char[], int);
void players_turn(int, bool&, int&, int&, char[], int);
bool error(int, char);
void exit(int, bool&);
void time_out(int, bool&);
void wrong_color(int, bool&, char[], int);
void reset(int, int&, int&);
char simon_says(int);
void simon_color(char);

//==========================================================
//
//	Main Function

int main()
{
	int lang;
	
	system("title Simon Says !");
	
	language(lang);
	welcome(lang);
	rules(lang);
	lets_play(lang);
	
	return 0;
}

//==========================================================
//
//	Language selection

void language(int& lang)
{
	system("color 17");
	do
	{
		system("cls");
		cout << "\n\n\tChoose Language / Seleccione Idioma:\n\n"
			 << "\tEnglish ===> 1\n\tEspanol ===> 2\n\n\t===> ";
		cin >> lang;
		
		if(lang != 1 && lang != 2)
		{
			cout << "\nERROR: Wrong Selection / Seleccion Invalida.";
		}
	}
	while(lang != 1 && lang != 2);
}

//==========================================================
//
//	Welcome

void welcome(int lang)
{
	system("cls");
	system("color 0A");
	
	if(lang == 1)
	{
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
	else
	{
		cout << endl
			 << "\t _____\n"
			 << "\t| __  |\n"
			 << "\t| __ -|\n"
			 << "\t|_____|";
		Sleep(500);
		system("cls");
		cout << endl
			 << "\t _____ _\n"
			 << "\t| __  |_|\n"
			 << "\t| __ -| |\n"
			 << "\t|_____|_|";
		Sleep(500);
		system("cls");
		cout << endl
			 << "\t _____ _\n"
			 << "\t| __  |_|___\n"
			 << "\t| __ -| | -_|\n"
			 << "\t|_____|_|___|";
		Sleep(500);
		system("cls");
		cout << endl
			 << "\t _____ _\n"
			 << "\t| __  |_|___ ___\n"
			 << "\t| __ -| | -_|   |\n"
			 << "\t|_____|_|___|_|_|";
		Sleep(500);
		system("cls");
		cout << endl
			 << "\t _____ _\n"
			 << "\t| __  |_|___ ___ _ _\n"
			 << "\t| __ -| | -_|   | | |\n"
			 << "\t|_____|_|___|_|_|\\_/";
		Sleep(500);
		system("cls");
		cout << endl
			 << "\t _____ _\n"
			 << "\t| __  |_|___ ___ _ _ ___\n"
			 << "\t| __ -| | -_|   | | | -_|\n"
			 << "\t|_____|_|___|_|_|\\_/|___|";
		Sleep(500);
		system("cls");
		cout << endl
			 << "\t _____ _\n"
			 << "\t| __  |_|___ ___ _ _ ___ ___\n"
			 << "\t| __ -| | -_|   | | | -_|   |\n"
			 << "\t|_____|_|___|_|_|\\_/|___|_|_|";
		Sleep(500);
		system("cls");
		cout << endl
			 << "\t _____ _                     _\n"
			 << "\t| __  |_|___ ___ _ _ ___ ___|_|\n"
			 << "\t| __ -| | -_|   | | | -_|   | |\n"
			 << "\t|_____|_|___|_|_|\\_/|___|_|_|_|";
		Sleep(500);
		system("cls");
		cout << endl
			 << "\t _____ _                     _   _\n"
			 << "\t| __  |_|___ ___ _ _ ___ ___|_|_| |\n"
			 << "\t| __ -| | -_|   | | | -_|   | | . |\n"
			 << "\t|_____|_|___|_|_|\\_/|___|_|_|_|___|";
		Sleep(500);
		system("cls");
		cout << endl
			 << "\t _____ _                     _   _\n"
			 << "\t| __  |_|___ ___ _ _ ___ ___|_|_| |___\n"
			 << "\t| __ -| | -_|   | | | -_|   | | . | . |\n"
			 << "\t|_____|_|___|_|_|\\_/|___|_|_|_|___|___|";
		Sleep(2000);
	}
}

//==========================================================
//
//	Rules

void rules(int lang)
{
	if(lang == 1)
	{
		cout << "\n\n\t\tSimon Says !\n"
			 << "\t\t============\n\n"
			 << "\tRules:\n"
			 << "\tSimon will pick a random color each turn.\n"
			 << "\tYou must remember the full color combination\n"
			 << "\tand repeat it by typing it. There are 4 colors:\n\n"
			 << "\tRed ===> R\n\tGreen ===> G\n\tBlue ===> B\n\tYellow ===> Y\n\n"
			 << "\t---------------------------------------------\n\n"
			 << "\tType 'E' to exit whenever you want to.\n\n\t";
	}
	else
	{
		cout << "\n\n\t\tSimon Dice !\n"
			 << "\t\t============\n\n"
			 << "\tReglas:\n"
			 << "\tSimon elegira un color al azar cada turno.\n"
			 << "\tDebe recordar la combinacion completa de colores\n"
			 << "\ty repetirla durante su turno. Hay 4 colores:\n\n"
			 << "\tRojo ===> R\n\tVerde ===> V\n\tAzul ===> A\n\tAmarillo ===> X\n\n"
			 << "\t---------------------------------------------\n\n"
			 << "\tIntroduzca 'E' para salir cuando lo desee.\n\n\t";
	}
	
	system("pause");
	system("cls");
}

//==========================================================
//
//	Game Heart <3

void lets_play(int lang)
{
	int turn(1), count(0), speed, chrono;
	char simon[200];
	bool end = false;
	
	difficulty(lang, speed, chrono);
	
	for(int x = 1; x <= 200; x++)
	{
		if(turn == 1)
		{
			simons_turn(lang, turn, count, simon, speed);
		}
		else
		{
			players_turn(lang, end, turn, count, simon, chrono);
			
			if(end)
			{
				return;
			}
		}
	}
}

//==========================================================
//
//	Select Difficulty

void difficulty(int lang, int& speed, int& chrono)
{
	int selection;
	
	if(lang == 1)
	{
		do
		{
			cout << "\n"
				 << "\t ____  _ ___ ___ _         _ _\n"
				 << "\t|    \\|_|  _|  _|_|___ _ _| | |_ _ _\n"
				 << "\t|  |  | |  _|  _| |  _| | | |  _| | |\n"
				 << "\t|____/|_|_| |_| |_|___|___|_|_| |_  |\n"
				 << "\t                                |___|\n\n"
				 << "\tEasy ===> 1\n"
				 << "\tSimon shows colors for 1s\n"
				 << "\tYou have 10s to give an answer.\n\n"
				 << "\tHard ===> 2\n"
				 << "\tSimon shows colors for 0.5s\n"
				 << "\tYou have 5s to give an answer.\n\n"
				 << "\tSelection: ";
			cin >> selection;
			
			if(selection != 1 && selection != 2)
			{
				cout << "\n\tERROR: Wrong Selection.\n";
				Sleep(1000);
				system("cls");
			}
		}
		while(selection != 1 && selection != 2);
	}
	else
	{
		do
		{
			cout << "\n"
				 << "\t ____  _ ___ _         _ _         _\n"
				 << "\t|    \\|_|  _|_|___ _ _| | |_ ___ _| |\n"
				 << "\t|  |  | |  _| |  _| | | |  _| .'| . |\n"
				 << "\t|____/|_|_| |_|___|___|_|_| |__,|___|\n\n"
				 << "\tFacil ===> 1\n"
				 << "\tSimon muestra cada color durante 1s\n"
				 << "\tTiene 10s para responder cada color.\n\n"
				 << "\tDificil ===> 2\n"
				 << "\tSimon muestra cada color durante 0.5s\n"
				 << "\tTiene 5s para responder cada color.\n\n"
				 << "\tSeleccion: ";
			cin >> selection;
			
			if(selection != 1 && selection != 2)
			{
				cout << "\n\tERROR: Seleccion Invalida.\n";
				Sleep(1000);
				system("cls");
			}
		}
		while(selection != 1 && selection != 2);
	}
	
	if(selection == 1)
	{
		speed = 1000;
		chrono = 10;
	}
	else
	{
		speed = 500;
		chrono = 5;
	}
	
	system("cls");
}

//==========================================================
//
//	Simon's Turn

void simons_turn(int lang, int& turn, int count, char simon[], int speed)
{
	cout << "\n"
		 << "\t _____ _\n"
		 << "\t|   __|_|_____ ___ ___\n"
		 << "\t|__   | |     | . |   |\n"
		 << "\t|_____|_|_|_|_|___|_|_|";
	
	simon[count] = simon_says(lang);
	
	for(int y = 0; y <= count; y++)
	{
		Sleep(500);
		simon_color(simon[y]);
		Sleep(speed);
		system("color 0A");
	}
	
	Sleep(500);
	turn = 2;
	system("cls");
}

//==========================================================
//
//	Player's Turn

void players_turn(int lang, bool& end, int& turn, int& count, char simon[], int chrono)
{
	char player;
	time_t chrono_start, chrono_end;
	
	if(lang == 1)
	{
		cout << "\n"
			 << "\t __ __\n"
			 << "\t|  |  |___ _ _\n"
			 << "\t|_   _| . | | |\n"
			 << "\t  |_| |___|___|        Timer: " << chrono << "s/color\n\n";
	}
	else
	{
		cout << "\n"
			 << "\t _____     _         _\n"
			 << "\t|  |  |___| |_ ___ _| |\n"
			 << "\t|  |  |_ -|  _| -_| . |\n"
			 << "\t|_____|___|_| |___|___|    Tiempo: " << chrono << "s/color\n\n";
	}

	for(int z = 0; z <= count; z++)
	{
		chrono_start = time(NULL);
		
		do
		{
			cout << "\t";
			cin >> player;
			
			if(error(lang, player))
			{
				cout << beep << "\n\tERROR: Wrong Selection. Try Again:\n\n";
			}
		}
		while(error(lang, player));
		
		if(player == 'E' || player == 'e')
		{
			exit(lang, end);
			return;
		}
		
		chrono_end = time(NULL);
		
		if(difftime(chrono_end, chrono_start) >= chrono)
		{
			time_out(lang, end);
			return;
		}
		
		if(player != simon[z] && int(player) != (int(simon[z]) + 32))
		{
			wrong_color(lang, end, simon, z);
			return;
		}
		
		simon_color(player);
		Sleep(500);
		system("color 0A");
	}
	
	reset(lang, turn, count);
}

//==========================================================
//
//	Player ERROR selection

bool error(int lang, char player)
{
	if(lang == 1)
	{
		return (player != 'R' && player != 'r' && player != 'G' && player != 'g' && player != 'B' && player != 'b'&& player != 'Y' && player != 'y' && player != 'E' && player != 'e');
	}
	else
	{
		return (player != 'R' && player != 'r' && player != 'V' && player != 'v' && player != 'A' && player != 'a'&& player != 'X' && player != 'x' && player != 'E' && player != 'e');
	}
}

//==========================================================
//
//	Exit

void exit(int lang, bool& end)
{
	end = true;
	system("cls");
	system("color 0A");
	
	if(lang == 1)
	{
		cout << "\n"
			 << "\t _____ _           _          ___\n"
			 << "\t|_   _| |_ ___ ___| |_ ___   |  _|___ ___\n"
			 << "\t  | | |   | .'|   | '_|_ -|  |  _| . |  _|\n"
			 << "\t  |_| |_|_|__,|_|_|_,_|___|  |_| |___|_|\n\n"
			 << "\t                            __ __ __\n"
			 << "\t     _         _           |  |  |  |\n"
			 << "\t ___| |___ _ _|_|___ ___   |  |  |  |\n"
			 << "\t| . | | .'| | | |   | . |  |__|__|__|\n"
			 << "\t|  _|_|__,|_  |_|_|_|_  |  |__|__|__|\n"
			 << "\t|_|       |___|     |___|\n\n\t";
	}
	else
	{
		cout << "\n"
			 << "\t _____             _\n"
			 << "\t|   __|___ ___ ___|_|___ ___    ___ ___ ___\n"
			 << "\t|  |  |  _| .'|  _| | .'|_ -|  | . | . |  _|\n"
			 << "\t|_____|_| |__,|___|_|__,|___|  |  _|___|_|\n"
			 << "\t                               |_|\n\n"
			 << "\t                          __ __ __\n"
			 << "\t    __                   |  |  |  |\n"
			 << "\t __|  |_ _ ___ ___ ___   |  |  |  |\n"
			 << "\t|  |  | | | . | .'|  _|  |__|__|__|\n"
			 << "\t|_____|___|_  |__,|_|    |__|__|__|\n"
			 << "\t          |___|\n\n\t";
	}
	
	system("pause");
}

//==========================================================
//
//	GAME OVER: Out of Time

void time_out(int lang, bool& end)
{
	end = true;
	
	if(lang == 1)
	{
		cout << beep << "\n\tOut of time !!!\n\n";
	}
	else
	{
		cout << beep << "\n\tFuera de Tiempo !!!\n\n";
	}
	
	cout << "\t _____ _____ _____ _____    _____ _____ _____ _____\n"
		 << "\t|   __|  _  |     |   __|  |     |  |  |   __| __  |\n"
		 << "\t|  |  |     | | | |   __|  |  |  |  |  |   __|    -|\n"
		 << "\t|_____|__|__|_|_|_|_____|  |_____|\\___/|_____|__|__|\n\n\t";
	system("pause");
}

//==========================================================
//
//	GAME OVER: Wrong Color

void wrong_color(int lang, bool& end, char simon[], int z)
{
	end = true;
	simon_color(simon[z]);
	
	if(lang == 1)
	{
		cout << beep << "\n\tERROR: The correct answer was: " << simon[z] << "\n\n";
	}
	else
	{
		cout << beep << "\n\tERROR: La respuesta correcta era: " << simon[z] << "\n\n";
	}
	
	cout << "\t _____ _____ _____ _____    _____ _____ _____ _____\n"
		 << "\t|   __|  _  |     |   __|  |     |  |  |   __| __  |\n"
		 << "\t|  |  |     | | | |   __|  |  |  |  |  |   __|    -|\n"
		 << "\t|_____|__|__|_|_|_|_____|  |_____|\\___/|_____|__|__|\n\n\t";
	system("pause");
}

//==========================================================
//
//	Reset variables

void reset(int lang, int& turn, int& count)
{
	count++;
	turn = 1;
	
	if(lang == 1)
	{
		cout << "\n\tWell Done !!!";
	}
	else
	{
		cout << "\n\tPerfecto !!!";
	}
	
	Sleep(1000);
	system("color 0A");
	system("cls");
}

//==========================================================
//
//	Says a random color

char simon_says(int lang)
{
	int random;
	
	srand(time(NULL));
	
	random = rand() % 4;
	
	if(lang == 1)
	{
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
	else
	{
		if(random == 0)
		{
			return 'R';
		} else if(random == 1)
		{
			return 'V';
		} else if(random == 2)
		{
			return 'A';
		} else
		{
			return 'X';
		}
	}
}

//==========================================================
//
//	Paints Screen

void simon_color(char color)
{
	if(color == 'R' || color == 'r')
	{
		system("color C0");
	} else if(color == 'G' || color == 'g' || color == 'V' || color == 'v')
	{
		system("color A0");
	} else if(color == 'B' || color == 'b' || color == 'A' || color == 'a')
	{
		system("color 30");
	} else
	{
		system("color 60");
	}
}