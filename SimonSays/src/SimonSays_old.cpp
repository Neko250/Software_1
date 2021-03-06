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

// Global Functions
void language(int&);
void lets_play(int);
void reset(int&, int&);
void simon_color(char);

// English Functions
void welcome();
void rules();
void difficulty(int&, int&);
void simons_turn(int&, int, char[], int);
void players_turn(bool&, int&, int&, char[], int);
bool error(char&);
void exit(bool&);
void time_out(bool&);
void wrong_color(bool&, char[], int);
char simon_says();

// Spanish Functions
void bienvenida();
void reglas();
void dificultad(int&, int&);
void turno_simon(int&, int, char[], int);
void turno_jugador(bool&, int&, int&, char[], int);
bool error_sp(char&);
void salir(bool&);
void fuera_tiempo(bool&);
void color_erroneo(bool&, char[], int);
char simon_dice();

//==========================================================
//
//	Main Function

int main()
{
	int lang;
	
	language(lang);
	
	if(lang == 1)
	{
		welcome();
		rules();
		lets_play(lang);
	}
	else
	{
		bienvenida();
		reglas();
		lets_play(lang);
	}
	return 0;
}

//==========================================================
//=======================          =========================
//=======================  GLOBAL  =========================
//=======================          =========================
//==========================================================

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
			 << "\tEnglish ===> 1\n\tEspa�ol ===> 2\n\n\t===> ";
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
//	Game Heart <3

void lets_play(int lang)
{
	int turn(1), count(0), speed, chrono;
	char simon[200];
	bool end = false;
	
	if(lang == 1)
	{
		difficulty(speed, chrono);
		
		for(int x = 1; x <= 200; x++)
		{
			if(turn == 1)
			{
				simons_turn(turn, count, simon, speed);
			}
			else
			{
				players_turn(end, turn, count, simon, chrono);
				
				if(end)
				{
					return;
				}
			}
		}
	}
	else
	{
		dificultad(speed, chrono);
		
		for(int x = 1; x <= 200; x++)
		{
			if(turn == 1)
			{
				turno_simon(turn, count, simon, speed);
			}
			else
			{
				turno_jugador(end, turn, count, simon, chrono);
				
				if(end)
				{
					return;
				}
			}
		}
	}
}

//==========================================================
//
//	Reset variables

void reset(int& turn, int& count)
{
	count++;
	turn = 1;
	Sleep(1000);
	system("color 0A");
	system("cls");
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

//==========================================================
//======================           =========================
//======================  ENGLISH  =========================
//======================           =========================
//==========================================================

//==========================================================
//
//	Welcome

void welcome()
{
	system("cls");
	system("color 0A");
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

//==========================================================
//
//	Rules

void rules()
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
	system("pause");
	system("cls");
}

//==========================================================
//
//	Select Difficulty

void difficulty(int& speed, int& chrono)
{
	int selection;
	
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

void simons_turn(int& turn, int count, char simon[], int speed)
{
	cout << "\n"
		 << "\t _____ _\n"
		 << "\t|   __|_|_____ ___ ___\n"
		 << "\t|__   | |     | . |   |\n"
		 << "\t|_____|_|_|_|_|___|_|_|";
	
	simon[count] = simon_says();
	
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

void players_turn(bool& end, int& turn, int& count, char simon[], int chrono)
{
	char player;
	time_t chrono_start, chrono_end;
	
	cout << "\n"
		 << "\t __ __\n"
		 << "\t|  |  |___ _ _\n"
		 << "\t|_   _| . | | |\n"
		 << "\t  |_| |___|___|        Timer: " << chrono << "s/color\n\n";

	for(int z = 0; z <= count; z++)
	{
		chrono_start = time(NULL);
		
		do
		{
			cout << "\t";
			cin >> player;
			
			if(error(player))
			{
				cout << "\n\tERROR: Wrong Selection. Try Again:\n\n";
			}
		}
		while(error(player));
		
		if(player == 'E' || player == 'e')
		{
			exit(end);
			return;
		}
		
		chrono_end = time(NULL);
		
		if(difftime(chrono_end, chrono_start) >= chrono)
		{
			time_out(end);
			return;
		}
		
		if(player != simon[z] && int(player) != (int(simon[z]) + 32))
		{
			wrong_color(end, simon, z);
			return;
		}
		
		simon_color(player);
		Sleep(500);
		system("color 0A");
	}
	
	cout << "\n\tWell Done !!!";
	reset(turn, count);
}

//==========================================================
//
//	Player ERROR selection

bool error(char& player)
{
	return (player != 'R' && player != 'r' && player != 'G' && player != 'g' && player != 'B' && player != 'b'&& player != 'Y' && player != 'y' && player != 'E' && player != 'e');
}

//==========================================================
//
//	Exit

void exit(bool& end)
{
	end = true;
	system("cls");
	system("color 0A");
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
	system("pause");
}

//==========================================================
//
//	GAME OVER: Out of Time

void time_out(bool& end)
{
	end = true;
	cout << "\n\tOut of time !!!\n\n"
		 << "\t _____ _____ _____ _____    _____ _____ _____ _____\n"
		 << "\t|   __|  _  |     |   __|  |     |  |  |   __| __  |\n"
		 << "\t|  |  |     | | | |   __|  |  |  |  |  |   __|    -|\n"
		 << "\t|_____|__|__|_|_|_|_____|  |_____|\\___/|_____|__|__|\n\n\t";
	system("pause");
}

//==========================================================
//
//	GAME OVER: Wrong Color

void wrong_color(bool& end, char simon[], int z)
{
	end = true;
	simon_color(simon[z]);
	cout << "\n\tERROR: The correct answer was: " << simon[z] << "\n\n"
		 << "\t _____ _____ _____ _____    _____ _____ _____ _____\n"
		 << "\t|   __|  _  |     |   __|  |     |  |  |   __| __  |\n"
		 << "\t|  |  |     | | | |   __|  |  |  |  |  |   __|    -|\n"
		 << "\t|_____|__|__|_|_|_|_____|  |_____|\\___/|_____|__|__|\n\n\t";
	system("pause");
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
//======================           =========================
//======================  SPANISH  =========================
//======================           =========================
//==========================================================

//==========================================================
//
//	Welcome

void bienvenida()
{
	system("cls");
	system("color 0A");
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

//==========================================================
//
//	Rules

void reglas()
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
	system("pause");
	system("cls");
}

//==========================================================
//
//	Select Difficulty

void dificultad(int& speed, int& chrono)
{
	int selection;
	
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

void turno_simon(int& turn, int count, char simon[], int speed)
{
	cout << "\n"
		 << "\t _____ _\n"
		 << "\t|   __|_|_____ ___ ___\n"
		 << "\t|__   | |     | . |   |\n"
		 << "\t|_____|_|_|_|_|___|_|_|";
	
	simon[count] = simon_dice();
	
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

void turno_jugador(bool& end, int& turn, int& count, char simon[], int chrono)
{
	char player;
	time_t chrono_start, chrono_end;
	
	cout << "\n"
		 << "\t _____     _         _\n"
		 << "\t|  |  |___| |_ ___ _| |\n"
		 << "\t|  |  |_ -|  _| -_| . |\n"
		 << "\t|_____|___|_| |___|___|    Tiempo: " << chrono << "s/color\n\n";

	for(int z = 0; z <= count; z++)
	{
		chrono_start = time(NULL);
		
		do
		{
			cout << "\t";
			cin >> player;
			
			if(error_sp(player))
			{
				cout << "\n\tERROR: Seleccion Invalida.\n"
					 << "\tIntentelo de nuevo:\n\n";
			}
		}
		while(error_sp(player));
		
		if(player == 'E' || player == 'e')
		{
			salir(end);
			return;
		}
		
		chrono_end = time(NULL);
		
		if(difftime(chrono_end, chrono_start) >= chrono)
		{
			fuera_tiempo(end);
			return;
		}
		
		if(player != simon[z] && int(player) != (int(simon[z]) + 32))
		{
			color_erroneo(end, simon, z);
			return;
		}
		
		simon_color(player);
		Sleep(500);
		system("color 0A");
	}
	
	cout << "\n\tPerfecto !!!";
	reset(turn, count);
}

//==========================================================
//
//	Player ERROR selection

bool error_sp(char& player)
{
	return (player != 'R' && player != 'r' && player != 'V' && player != 'v' && player != 'A' && player != 'a'&& player != 'X' && player != 'x' && player != 'E' && player != 'e');
}

//==========================================================
//
//	Exit

void salir(bool& end)
{
	end = true;
	system("cls");
	system("color 0A");
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
	system("pause");
}

//==========================================================
//
//	GAME OVER: Out of Time

void fuera_tiempo(bool& end)
{
	end = true;
	cout << "\n\tFuera de Tiempo !!!\n\n"
		 << "\t _____ _____ _____ _____    _____ _____ _____ _____\n"
		 << "\t|   __|  _  |     |   __|  |     |  |  |   __| __  |\n"
		 << "\t|  |  |     | | | |   __|  |  |  |  |  |   __|    -|\n"
		 << "\t|_____|__|__|_|_|_|_____|  |_____|\\___/|_____|__|__|\n\n\t";
	system("pause");
}

//==========================================================
//
//	GAME OVER: Wrong Color

void color_erroneo(bool& end, char simon[], int z)
{
	end = true;
	simon_color(simon[z]);
	cout << "\n\tERROR: La respuesta correcta era: " << simon[z] << "\n\n"
		 << "\t _____ _____ _____ _____    _____ _____ _____ _____\n"
		 << "\t|   __|  _  |     |   __|  |     |  |  |   __| __  |\n"
		 << "\t|  |  |     | | | |   __|  |  |  |  |  |   __|    -|\n"
		 << "\t|_____|__|__|_|_|_|_____|  |_____|\\___/|_____|__|__|\n\n\t";
	system("pause");
}

//==========================================================
//
//	Says a random color

char simon_dice()
{
	int random;
	
	srand(time(NULL));
	
	random = rand() % 4;
	
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