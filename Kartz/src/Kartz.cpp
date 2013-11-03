
//=================================

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "VK.cpp"
using namespace std;

//=================================

void setScreen();

void clearBufer();
void setCursor(int, int);
void setCursor(COORD);
void setColor(int);
void hideConsoleCursor();

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

struct ufo_t
{
	int pos;
	
	void print()
	{
		setColor(light_green);
		
		switch(pos)
		{
			case 0:
				setCursor(3, 26);
				cout << b << b << b << b;
				setCursor(2, 27);
				cout << b << b << b << b << b << b;
				setCursor(1, 28);
				cout << b << b << b << "  " << b << b << b;
				setCursor(1, 29);
				cout << b << b << "    " << b << b;
				break;
			case 1:
				setCursor(11, 26);
				cout << b << b << b << b;
				setCursor(10, 27);
				cout << b << b << b << b << b << b;
				setCursor(9, 28);
				cout << b << b << b << "  " << b << b << b;
				setCursor(9, 29);
				cout << b << b << "    " << b << b;
				break;
			case 2:
				setCursor(19, 26);
				cout << b << b << b << b;
				setCursor(18, 27);
				cout << b << b << b << b << b << b;
				setCursor(17, 28);
				cout << b << b << b << "  " << b << b << b;
				setCursor(17, 29);
				cout << b << b << "    " << b << b;
				break;
		}
	}
	
	void erase()
	{
		switch(pos)
		{
			case 0:
				setCursor(3, 26);
				cout << "    ";
				setCursor(2, 27);
				cout << "      ";
				setCursor(1, 28);
				cout << "        ";
				setCursor(1, 29);
				cout << "        ";
				break;
			case 1:
				setCursor(11, 26);
				cout << "    ";
				setCursor(10, 27);
				cout << "      ";
				setCursor(9, 28);
				cout << "        ";
				setCursor(9, 29);
				cout << "        ";
				break;
			case 2:
				setCursor(19, 26);
				cout << "    ";
				setCursor(18, 27);
				cout << "      ";
				setCursor(17, 28);
				cout << "        ";
				setCursor(17, 29);
				cout << "        ";
				break;
		}
	}
	
	void flash()
	{
		for(int i = 0; i < 6; i++)
		{
			if(i % 2 == 0)
			{
				erase();
			}
			else
			{
				print();
			}
			
			Beep(998, 100);
			Sleep(150);
		}
	}
	
	void reset()
	{
		pos = 1;
		print();
	}
	
	void listen(int step, bool& run, bool& game)
	{
		if(GetAsyncKeyState(VK_Esc))
		{
			run = false;
			game = false;
			Sleep(250);
		}
		
		if(GetAsyncKeyState(VK_Left))
		{
			erase();
			
			if(pos > 0)
			{
				pos--;
			}
			
			print();
			
			Sleep(step);
		}
		
		if(GetAsyncKeyState(VK_Right))
		{
			erase();
			
			if(pos < 2)
			{
				pos++;
			}
			
			print();
			
			Sleep(step);
		}
	}
};

//=================================

void play(ufo_t&);
void printObstacle(int);
void obstacleGen(int&, int&, int&, int&, int&);
bool dead(int, int);
void gameOver(ufo_t&, int&, int&, int&, int&, int&, int&, float&, bool&);
void scoreBoard(int&, int);

//=================================

int main()
{
	ufo_t ufo;
	
	system("mode con: lines=35 cols=26");
	hideConsoleCursor();
	setScreen();
	
	play(ufo);
	
	Sleep(500);
	return 0;
}

//=================================

void play(ufo_t& ufo)
{
	int obs0 = 6, obs1 = 6, obs2 = 6, obs3 = 6, obs4 = 6, score = 0;
	float freq = 1.000;
	
	clock_t step_start, step_now, move_start, move_now;
	
	ufo.reset();
	
	for(bool run = true; run; )
	{
		for(bool game = true; game; )
		{
			step_start = clock();
			step_now = clock();
			
			while(((float(step_now) / CLOCKS_PER_SEC)-(float(step_start) / CLOCKS_PER_SEC)) < freq)
			{
				ufo.listen(100, run, game);
				step_now = clock();
			}
			
			if(dead(ufo.pos, obs4))
			{
				gameOver(ufo, obs0, obs1, obs2, obs3, obs4, score, freq, game);
			}
			
			scoreBoard(score, obs4);
			obstacleGen(obs0, obs1, obs2, obs3, obs4);
			
			if((score != 0) && (score % 25 == 0) && (freq > 0.300))
			{
				freq -= 0.125;
			}
		}
	}
}

//=================================

void printObstacle(int num)
{
	switch(num)
	{
		case 0:
			cout << "--------        --------";
			break;
		case 1:
			cout << "----------------        ";
			break;
		case 2:
			cout << "        ----------------";
			break;
		case 3:
			cout << "--------                ";
			break;
		case 4:
			cout << "        --------        ";
			break;
		case 5:
			cout << "                --------";
			break;
		default:
			cout << "                        ";
			break;
	}
}

//=================================

void obstacleGen(int& obs0, int& obs1, int& obs2, int& obs3, int& obs4)
{
	int temp;
	
	srand(time(NULL));
	
	obs4 = obs3;
	obs3 = obs2;
	obs2 = obs1;
	obs1 = obs0;
	
	do
	{
		temp = rand() % 6;
	}
	while(obs0 == temp);
	
	obs0 = temp;
	
	Beep(784, 100);
	
	setColor(light_green);
	
	setCursor(1, 5);
	cout << "                        ";
	setCursor(1, 5);
	printObstacle(obs0);
	setCursor(1, 10);
	cout << "                        ";
	setCursor(1, 10);
	printObstacle(obs1);
	setCursor(1, 15);
	cout << "                        ";
	setCursor(1, 15);
	printObstacle(obs2);
	setCursor(1, 20);
	cout << "                        ";
	setCursor(1, 20);
	printObstacle(obs3);
	setCursor(1, 25);
	cout << "                        ";
	setCursor(1, 25);
	printObstacle(obs4);
}

//=================================

bool dead(int pos, int obstacle)
{
	bool ans = false;
	
	if( (pos == 0 && (obstacle == 0 || obstacle == 1 || obstacle == 3)) ||
		(pos == 1 && (obstacle == 1 || obstacle == 2 || obstacle == 4)) ||
		(pos == 2 && (obstacle == 0 || obstacle == 2 || obstacle == 5)) )
	{
		ans = true;
	}
	
	return ans;
}

//=================================

void gameOver(ufo_t& ufo, int& obs0, int& obs1,
				int& obs2, int& obs3, int& obs4,
				int& score, float& freq, bool& game)
{
	ufo.flash();
	setScreen();
	ufo.reset();
	obs0 = 6;
	obs1 = 6;
	obs2 = 6;
	obs3 = 6;
	obs4 = 6;
	score = 0;
	freq = 1.000;
	
	game = false;
}

//=================================

void scoreBoard(int& score, int obs4)
{
	if(obs4 != 6)
	{
		score++;
	}
	
	setColor(light_red);
	setCursor(14, 32);
	
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
}

//=================================

void setScreen()
{
	setColor(light_green);
	
	setCursor(0, 0);
	cout << " ------------------------";
	
	for(int i = 1; i < 30; i++)
	{
		setCursor(0, i);
		cout << "|                        |";
	}
	
	setCursor(0, 30);
	cout << " ------------------------ ";
	//setCursor(0, 31);
	cout << "|                        |";
	//setCursor(0, 32);
	cout << "|       ";
	setColor(light_red);
	cout << "0.000.000p";
	setColor(light_green);
	cout << "       |";
	//setCursor(0, 33);
	cout << "|                        |";
	//setCursor(0, 34);
	cout << " ------------------------";
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

