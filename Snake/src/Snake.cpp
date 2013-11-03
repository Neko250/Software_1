#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "VK.cpp"
using namespace std;

//===================================

void listen(int&, bool&);

void clearBufer();
void setCursor(int, int);
void setCursor(COORD);
void setColor(int);
void hideConsoleCursor();

//===================================

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

const int tamano = 100;

struct seccion
{
	COORD pos;
	bool state;
};

typedef seccion cuerpo_t[tamano];

struct snake_t
{
	int dir, next;
	cuerpo_t cuerpo;
	
	void print()
	{
		setColor(light_green);
		for(int i = 0; ((i < tamano) && (cuerpo[i].state)); i++)
		{
			setCursor(cuerpo[i].pos);
			cout << b;
		}
	}
	
	void update()
	{
		setCursor(cuerpo[(next - 1)].pos);
		cout << ' ';
		
		for(int i = (next - 1); i > 0; i--)
		{
			cuerpo[i].pos = cuerpo[(i - 1)].pos;
		}
		
		switch(dir)
		{
			case 0:
				cuerpo[0].pos.Y--;
				if(cuerpo[0].pos.Y < 1) cuerpo[0].pos.Y = 44;
				break;
			case 1:
				cuerpo[0].pos.X++;
				if(cuerpo[0].pos.X > 98) cuerpo[0].pos.X = 1;
				break;
			case 2:
				cuerpo[0].pos.Y++;
				if(cuerpo[0].pos.Y > 44) cuerpo[0].pos.Y = 1;
				break;
			case 3:
				cuerpo[0].pos.X--;
				if(cuerpo[0].pos.X < 1) cuerpo[0].pos.X = 98;
				break;
		}
		
		setCursor(cuerpo[0].pos);
		cout << b;
	}
	
	void reset()
	{
		dir = 0;
		next = 4;
		
		for(int i = 3; i < tamano; i++)
		{
			cuerpo[i].state = false;
			cuerpo[i].pos.X = 0;
			cuerpo[i].pos.Y = 0;
		}
		
		cuerpo[0].state = true;
		cuerpo[0].pos.X = 23;
		cuerpo[0].pos.Y = 14;
		cuerpo[1].state = true;
		cuerpo[1].pos.X = 23;
		cuerpo[1].pos.Y = 15;
		cuerpo[2].state = true;
		cuerpo[2].pos.X = 23;
		cuerpo[2].pos.Y = 16;
	}
};

//===================================

void setScreen();
void play(snake_t&);
void check(snake_t&, COORD&, int&, int&);
void foodGen(COORD&, const snake_t&);
void scoreBoard(int);
void gameOver(int, const snake_t&);

//===================================

int main()
{
	snake_t snake;
	
	system("mode con: lines=50 cols=100");
	hideConsoleCursor();
	
	setScreen();
	snake.reset();
	
	play(snake);
	
	return 0;
}

//=================================

void setScreen()
{
	setColor(gold);
	setCursor(0, 0);
	cout << " --------------------------------------------------------------------------------------------------";
	
	for(int i = 1; i < 45; i++)
	{
		setCursor(0, i);
		cout << "|                                                                                                  |";
	}
	
	setCursor(0, 45);
	cout << " -------------------------------------------------------------------------------------------------- ";
	cout << "|                                                                                  |               |";
	cout << "|                         ";
	setColor(light_aqua);
	cout << "Snake - Coded by Neko250 - 2013";
	setColor(gold);
	cout << "                          |   ";
	setColor(light_red);
	cout << "0.000.000";
	setColor(gold);
	cout << "   |";
	cout << "|                                                                                  |               |";
	cout << " --------------------------------------------------------------------------------------------------";
}

//=================================

void play(snake_t& snake)
{
	bool run = true;
	int freq = 110, score = 0;
	COORD food;
	
	snake.print();
	foodGen(food, snake);
	
	while(run)
	{
		listen(snake.dir, run);
		snake.update();
		check(snake, food, freq, score);
		Sleep(freq);
	}
}

//=================================

void check(snake_t& snake, COORD& food, int& freq, int& score)
{
	/*
	if(snake.cuerpo[0].pos.X == 0)
	{
		Sleep(500);
		system("cls");
		setScreen();
		snake.reset();
		snake.print();
		foodGen(food, snake);
		freq = 120;
	}
	else if(snake.cuerpo[0].pos.X == 99)
	{
		Sleep(500);
		system("cls");
		setScreen();
		snake.reset();
		snake.print();
		foodGen(food, snake);
		freq = 120;
	}
	else if(snake.cuerpo[0].pos.Y == 0)
	{
		Sleep(500);
		system("cls");
		setScreen();
		snake.reset();
		snake.print();
		foodGen(food, snake);
		freq = 120;
	}
	else if(snake.cuerpo[0].pos.Y == 49)
	{
		Sleep(500);
		system("cls");
		setScreen();
		snake.reset();
		snake.print();
		foodGen(food, snake);
		freq = 120;
	}
	*/
	
	for(int i = 1; i < snake.next; i++)
	{
		if(snake.cuerpo[0].pos.X == snake.cuerpo[i].pos.X &&
			snake.cuerpo[0].pos.Y == snake.cuerpo[i].pos.Y)
		{
			Sleep(500);
			gameOver(score, snake);
			system("cls");
			setScreen();
			snake.reset();
			snake.print();
			foodGen(food, snake);
			freq = 110;
			score = 0;
		}
	}
	
	if(snake.cuerpo[0].pos.X == food.X &&
		snake.cuerpo[0].pos.Y == food.Y)
	{
		cout << beep;
		snake.next++;
		snake.cuerpo[snake.next].state = true;
		setCursor(snake.cuerpo[snake.next].pos);
		score++;
		scoreBoard(score);
		foodGen(food, snake);
		freq -= 2;
		
		if(freq < 50)
		{
			freq = 50;
		}
	}
}

//=================================

void foodGen(COORD& food, const snake_t& snake)
{
	bool equal;
	
	srand(time(NULL));
	
	do
	{
		equal = false;
		
		food.X = (rand() % 98) + 1;
		food.Y = (rand() % 44) + 1;
		
		for(int i = 0; ((i < snake.next) && !equal); i++)
		{
			equal = (snake.cuerpo[i].pos.X == food.X &&
					 snake.cuerpo[i].pos.Y == food.Y);
		}
	}
	while(equal);
	
	setCursor(food);
	
	cout << 'O';
}

//=================================

void scoreBoard(int score)
{
	setColor(light_red);
	setCursor(93, 47);
	if(score < 10)
	{
		cout << "00" << score;
	}
	else if(score < 100)
	{
		cout << '0' << score;
	}
	else if(score < 1000)
	{
		cout << score;
	}
	
	setColor(light_green);
}

//=================================

void gameOver(int score, const snake_t& snake)
{
	for(int i = 0; i < snake.next; i++)
	{
		setCursor(snake.cuerpo[i].pos);
		cout << ' ';
	}
	
	setColor(light_aqua);
	setCursor(30, 12);
	cout << "_____                  _____";
	setCursor(29, 13);
	cout << "|   __|___ _____ ___   |     |_ _ ___ ___";
	setCursor(29, 14);
	cout << "|  |  | .'|     | -_|  |  |  | | | -_|  _|";
	setCursor(29, 15);
	cout << "|_____|__,|_|_|_|___|  |_____|\\_/|___|_|";
	
	setCursor(42, 21);
	cout << "Score: ";
	
	setColor(light_red);
	cout << "0.000.";
	
	if(score < 10)
	{
		cout << "00" << score;
	}
	else if(score < 100)
	{
		cout << '0' << score;
	}
	else if(score < 1000)
	{
		cout << score;
	}
	
	setColor(light_aqua);
	setCursor(31, 26);
	system("pause");
	
	setColor(light_green);
}

//=================================

void listen(int& dir, bool& run)
{
	if(GetAsyncKeyState(VK_Up) && (dir != 2))
	{
		dir = 0;
	}
	
	if(GetAsyncKeyState(VK_Down) && (dir != 0))
	{
		dir = 2;
	}
	
	if(GetAsyncKeyState(VK_Right) && (dir != 3))
	{
		dir = 1;
	}
	
	if(GetAsyncKeyState(VK_Left) && (dir != 1))
	{
		dir = 3;
	}
	
	if(GetAsyncKeyState(VK_Esc))
	{
		run = false;
		Sleep(250);
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
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConCurInf);
}

//=================================

