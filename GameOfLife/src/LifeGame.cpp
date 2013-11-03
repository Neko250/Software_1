
//=================================

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "VK.cpp"
using namespace std;

//=================================

void clearBufer();
void setCursor(int, int);
void setCursor(COORD);
void setColor(int);
void hideConsoleCursor();
void showConsoleCursor();

//=================================

const char b = 219;
const char beep = 7;

enum color
{
	/* 0 */ black,
	/* 1 */ blue,
	/* 2 */ green,
	/* 3 */ aqua,
	/* 4 */ red,
	/* 5 */ purple,
	/* 6 */ gold,
	/* 7 */ light_light_gray,
	/* 8 */ light_gray,
	/* 9 */ light_blue,
	/* 10 */ light_green,
	/* 11 */ light_aqua,
	/* 12 */ light_red,
	/* 13 */ pink,
	/* 14 */ white,
	/* 15 */ gray
};

const int columnas = 100;
const int filas = 45;

typedef bool matriz[filas][columnas];

//=================================

void play(matriz&);
void update(matriz&);
bool surroundings(int, int, matriz&);
void listen(bool&, COORD&, matriz&);
void setScreen();
void resetTablero(matriz&);

//=================================

int main()
{
	COORD cursor;
	matriz tablero;
	
	system("mode con: lines=50 cols=100");
	
	for(bool run = true; run; )
	{
		hideConsoleCursor();
		setScreen();
		resetTablero(tablero);
		cursor.X = 49;
		cursor.Y = 20;
		setCursor(cursor);
		showConsoleCursor();
		listen(run, cursor, tablero);
		hideConsoleCursor();
		
		if(run)
		{
			play(tablero);
		}
	}
	
	return 0;
}

//=================================

void play(matriz& tablero)
{
	for(bool on = true; on; )
	{
		update(tablero);
		
		Sleep(100);
		
		if(GetAsyncKeyState(VK_Space))
		{
			on = false;
			Sleep(150);
		}
	}
}

//=================================

void update(matriz& tablero)
{
	matriz temp;
	
	resetTablero(temp);
	
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
		{
			temp[i][j] = surroundings(j, i, tablero);
		}
	}
	
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
		{
			tablero[i][j] = temp[i][j];
			setCursor(j, i);
			
			if(tablero[i][j])
			{
				cout << 'O';
			}
			else
			{
				cout << ' ';
			}
		}
	}
}

//=================================

bool surroundings(int x, int y, matriz& tablero)
{
	bool ans = false;
	int count = 0, x_temp, y_temp;
	
	for(int i = 0; i < 8; i++)
	{
		switch(i)
		{
			case 0:
				x_temp = x - 1;
				if(x_temp < 0) x_temp = 99;
				y_temp = y - 1;
				if(y_temp < 0) y_temp = 44;
				break;
			case 1:
				x_temp = x;
				y_temp = y - 1;
				if(y_temp < 0) y_temp = 44;
				break;
			case 2:
				x_temp = x + 1;
				if(x_temp > 99) x_temp = 0;
				y_temp = y - 1;
				if(y_temp < 0) y_temp = 44;
				break;
			case 3:
				x_temp = x - 1;
				if(x_temp < 0) x_temp = 99;
				y_temp = y;
				break;
			case 4:
				x_temp = x + 1;
				if(x_temp > 99) x_temp = 0;
				y_temp = y;
				break;
			case 5:
				x_temp = x - 1;
				if(x_temp < 0) x_temp = 99;
				y_temp = y + 1;
				if(y_temp > 44) y_temp = 0;
				break;
			case 6:
				x_temp = x;
				y_temp = y + 1;
				if(y_temp > 44) y_temp = 0;
				break;
			case 7:
				x_temp = x + 1;
				if(x_temp > 99) x_temp = 0;
				y_temp = y + 1;
				if(y_temp > 44) y_temp = 0;
				break;
		}
		
		if(tablero[y_temp][x_temp])
		{
			count++;
		}
	}
	
	if( ((count == 2 || count == 3) && tablero[y][x]) || count == 3)
	{
		ans = true;
	}
	
	return ans;
}

//=================================

void listen(bool& run, COORD& cursor, matriz& tablero)
{
	for(bool ask = true; ask; )
	{
		if(GetAsyncKeyState(VK_Left))
		{
			cursor.X--;
			if(cursor.X < 0) cursor.X = 99;
			setCursor(cursor);
			Sleep(100);
		}
		
		if(GetAsyncKeyState(VK_Right))
		{
			cursor.X++;
			if(cursor.X > 99) cursor.X = 0;
			setCursor(cursor);
			Sleep(100);
		}
		
		if(GetAsyncKeyState(VK_Up))
		{
			cursor.Y--;
			if(cursor.Y < 0) cursor.Y = 44;
			setCursor(cursor);
			Sleep(100);
		}
		
		if(GetAsyncKeyState(VK_Down))
		{
			cursor.Y++;
			if(cursor.Y > 44) cursor.Y = 0;
			setCursor(cursor);
			Sleep(100);
		}
		
		if(GetAsyncKeyState(VK_X))
		{
			cout << ' ';
			setCursor(cursor);
			tablero[cursor.Y][cursor.X] = false;
			Sleep(150);
		}
		
		if(GetAsyncKeyState(VK_C))
		{
			setColor(light_green);
			cout << 'O';
			setCursor(cursor);
			tablero[cursor.Y][cursor.X] = true;
			Sleep(150);
		}
		
		if(GetAsyncKeyState(VK_R))
		{
			hideConsoleCursor();
			resetTablero(tablero);
			cursor.X = 49;
			cursor.Y = 20;
			setCursor(cursor);
			showConsoleCursor();
			Sleep(150);
		}
		
		if(GetAsyncKeyState(VK_Space))
		{
			ask = false;
			Sleep(150);
		}
		
		if(GetAsyncKeyState(VK_Esc))
		{
			ask = false;
			run = false;
			Sleep(150);
		}
	}
}

//=================================

void setScreen()
{
	system("cls");
	setColor(gold);
	setCursor(0, 45);
	cout << " -------------------------------------------------------------------------------------------------- ";
	cout << "|                                                                                  |               |";
	cout << "|                       ";
	setColor(light_aqua);
	cout << "Life Game - Coded by Neko250 - 2013";
	setColor(gold);
	cout << "                        |  ";
	setColor(light_red);
	cout << "Version 1.0";
	setColor(gold);
	cout << "  |";
	cout << "|                                                                                  |               |";
	cout << " --------------------------------------------------------------------------------------------------";
}

//=================================

void resetTablero(matriz& tablero)
{
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
		{
			tablero[i][j] = false;
			setCursor(j, i);
			cout << ' ';
		}
	}
}

//=================================

void clearBufer()
{
	HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
}

//=================================

void setCursor(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//=================================

void setCursor(COORD pos)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//=================================

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//=================================

void hideConsoleCursor()
{
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize = 100;
	ConCurInf.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConCurInf);
}

//=================================

void showConsoleCursor()
{
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize = 100;
	ConCurInf.bVisible = true;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConCurInf);
}

//=================================

