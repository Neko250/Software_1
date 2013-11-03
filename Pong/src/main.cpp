#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#define K_Left 0x25
#define K_Right 0x27
#define K_A 0x41
#define K_D 0x44
#define K_Esc 0x1B
#define K_Space 0x20
#define K_C 0x43
#define K_R 0x52
#define K_S 0x53
#define K_Num1 0x61
#define K_Num2 0x62
#define K_Num3 0x63
#define K_1 0x31
#define K_2 0x32
#define K_3 0x33

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

const char beep = 7;



const int pala = 8;

const int cols = 40;
const int lines = 40;

typedef char vector[cols];
typedef char surface[lines][(cols + 1)];

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void title();
void difficulty(int&, bool&);
void setRow(vector&, int);
void printRow(const vector&, int);
void getKey(int&, int&, bool&, bool&, bool&);
void setBall(bool&, bool&, int&, int&, int, int, int&);
void setSurface(surface&, int, int);
void printSurface(const surface&, int, int);
bool checkOut(int, int, int, int);
void gameOver(int&, int&, int&, int&, int, bool&, bool&, bool&, int&, int&);
void openingSong();
void gameOverSong();
void clearBufer();

void printVoid();

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

int main()
{
	bool close = false, wait = true, run;
	
	int angle = 1, cont1 = 0, cont2 = 0, freq = 40;
	
	vector player1, player2;
	int start1 = ((cols/2)-(pala/2)), start2 = ((cols/2)-(pala/2));
	
	surface table;
	int x = 20, y = 39;
	bool right = true, up = true;
	
	system("title Pong !");
	
	// Tablero de 40x40
	system("mode con: lines=46 cols=40");
	
	title();
	difficulty(freq, close);
	
	while(!close)
	{
		while(wait)
		{
			setRow(player1, start1);
			setRow(player2, start2);
			setSurface(table, x, y);
			
			system("cls");
			cout << endl << endl;
			printRow(player1, start1);
			printSurface(table, x, y);
			printRow(player2, start2);
			
			cout << "\n\t Press Space to Serve...";
			
			Sleep(freq);
			
			getKey(start1, start2, close, run, wait);
		}
		
		while(run)
		{
			setRow(player1, start1);
			setRow(player2, start2);
			setBall(right, up, x, y, start1, start2, angle);
			setSurface(table, x, y);
			
			system("cls");
			cout << endl << endl;
			printRow(player1, start1);
			printSurface(table, x, y);
			printRow(player2, start2);
			
			if(checkOut(start1, start2, x, y))
			{
				gameOver(freq, start1, start2, x, y, close, run, wait, cont1, cont2);
			}
			
			//system("pause");
			Sleep(freq);
			
			getKey(start1, start2, close, run, wait);
		}
	}
	
	return 0;
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void title()
{
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n" << beep
		 << "\t ______\n"
		 << "\t(_____ \\\n"
		 << "\t _____) )\n"
		 << "\t|  ____/\n"
		 << "\t| |\n"
		 << "\t|_|";
	Sleep(500);
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n" << beep
		 << "\t ______\n"
		 << "\t(_____ \\\n"
		 << "\t _____) )__\n"
		 << "\t|  ____/ _ \\\n"
		 << "\t| |   | |_| |\n"
		 << "\t|_|    \\___/";
	Sleep(500);
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n" << beep
		 << "\t ______\n"
		 << "\t(_____ \\\n"
		 << "\t _____) )__  ____\n"
		 << "\t|  ____/ _ \\|  _ \\\n"
		 << "\t| |   | |_| | | | |\n"
		 << "\t|_|    \\___/|_| |_|";
	Sleep(500);
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n" << beep
		 << "\t ______\n"
		 << "\t(_____ \\\n"
		 << "\t _____) )__  ____   ____\n"
		 << "\t|  ____/ _ \\|  _ \\ / _  |\n"
		 << "\t| |   | |_| | | | ( (_| |\n"
		 << "\t|_|    \\___/|_| |_|\\___ |\n"
		 << "\t                  (_____|";
	Sleep(500);
	openingSong();
	Sleep(500);
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void difficulty(int& freq, bool& close)
{
	bool ans = false;
	
	system("cls");
	
	for(int i = 0; i < 15; i++)
	{
		cout << endl;
	}
	
	cout << "\t      Ball Speed:\n\n\n\n"
		 << "\t       1. Slow\n\n"
		 << "\t       2. Medium\n\n"
		 << "\t       3. Fast";
	
	clearBufer();
	
	while(!ans)
	{
		if(GetAsyncKeyState(K_Num1) || GetAsyncKeyState(K_1))
		{
			freq = 40;
			
			ans = true;
		}
		
		if(GetAsyncKeyState(K_Num2) || GetAsyncKeyState(K_2))
		{
			freq = 25;
			
			ans = true;
		}
		
		if(GetAsyncKeyState(K_Num3) || GetAsyncKeyState(K_3))
		{
			freq = 10;
			
			ans = true;
		}
		
		if(GetAsyncKeyState(K_Esc))
		{
			close = true;
			
			ans = true;
		}
	}
	
	clearBufer();
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void getKey(int& start1, int& start2, bool& close, bool& run, bool& wait)
{
	if(GetAsyncKeyState(K_Esc))
	{
		close = true;
		run = false;
		wait = false;
	}
	
	if(GetAsyncKeyState(K_Space))
	{
		run = true;
		wait = false;
	}
	
	if(GetAsyncKeyState(K_Left))
	{
		if(start1 > 0)
		{
			start1 -= 1;
		}
	}
	
	if(GetAsyncKeyState(K_Right))
	{
		if(start1 < cols-pala)
		{
			start1 += 1;
		}
	}
	
	if(GetAsyncKeyState(K_A))
	{
		if(start2 > 0)
		{
			start2 -= 1;
		}
	}
	
	if(GetAsyncKeyState(K_D))
	{
		if(start2 < cols-pala)
		{
			start2 += 1;
		}
	}
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void setRow(vector& row, int start)
{
	for(int i = 0; i < start; i++)
	{
		row[i] = ' ';
	}
	
	for(int k = start; k < (start + pala); k++)
	{
		row[k] = '=';
	}
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void printRow(const vector& row, int start)
{
	for(int i = 0; i < (start + pala); i++)
	{
		cout << row[i];
	}
	
	cout << endl;
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void setBall(bool& right, bool& up, int& x, int& y, int start1, int start2, int& angle)
{
	if(x == 0)
	{
		cout << beep;
		
		right = true;
	}
	else if(x == 39)
	{
		cout << beep;
		
		right = false;
	}
	
	if(y == 0)
	{
		cout << beep;
		
		up = false;
		
		if(x == start1)
		{
			right = false;
			angle = 3;
		}
		else if(x == (start1 + 1) || x == (start1 + 2))
		{
			right = false;
			angle = 2;
		}
		else if(x == (start1 + 3))
		{
			right = false;
			angle = 1;
		}
		else if(x == (start1 + 4))
		{
			right = true;
			angle = 1;
		}
		else if(x == (start1 + 5) || x == (start1 + 6))
		{
			right = true;
			angle = 2;
		}
		else if(x == (start1 + 7))
		{
			right = true;
			angle = 3;
		}
	}
	else if(y == 39)
	{
		cout << beep;
		
		up = true;
		
		if(x == start2)
		{
			right = false;
			angle = 3;
		}
		else if(x == (start2 + 1) || x == (start2 + 2))
		{
			right = false;
			angle = 2;
		}
		else if(x == (start2 + 3))
		{
			right = false;
			angle = 1;
		}
		else if(x == (start2 + 4))
		{
			right = true;
			angle = 1;
		}
		else if(x == (start2 + 5) || x == (start2 + 6))
		{
			right = true;
			angle = 2;
		}
		else if(x == (start2 + 7))
		{
			right = true;
			angle = 3;
		}
	}
	
	if(right)
	{
		x += angle;
		
		if(x > 39)
		{
			x = 39;
		}
	}
	else
	{
		x -= angle;
		
		if(x < 0)
		{
			x = 0;
		}
	}
	
	if(up)
	{
		y--;
	}
	else
	{
		y++;
	}
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void setSurface(surface& table, int x, int y)
{
	for(int k = 0; k < x; k++)
	{
		table[y][k] = ' ';
	}
	
	table[y][x] = '*';
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void printSurface(const surface& table, int x, int y)
{
	for(int i = 0; i < y; i++)
	{
		cout << endl;
	}
	
	for(int j = 0; j <= x; j++)
	{
		cout << table[y][j];
	}
	
	for(int k = 0; k < (lines - y); k++)
	{
		cout << endl;
	}
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

bool checkOut(int start1, int start2, int x, int y)
{
	if(y == 0)
	{
		if((x < start1) || ((start1 + pala - 1) < x))
		{
			return true;
		}
	}
	else if(y == 39)
	{
		if((x < start2) || ((start2 + pala - 1) < x))
		{
			return true;
		}
	}
	
	return false;
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void gameOver(int& freq,
			  int& start1,
			  int& start2,
			  int& x,
			  int y,
			  bool& close,
			  bool& run,
			  bool& wait,
			  int& cont1,
			  int& cont2)
{
	bool ans1 = false, ans2;
	
	gameOverSong();
	
	start1 = ((cols/2)-(pala/2));
	start2 = ((cols/2)-(pala/2));
	x = 20;
	
	wait = true;
	run = false;
	
	if(y == 0)
	{
		cont2++;
	}
	else if(y == 39)
	{
		cont1++;
	}
	
	clearBufer();
	
	while(!ans1)
	{
		ans2 = false;
		
		system("cls");
		
		for(int i = 0; i < 15; i++)
		{
			cout << endl;
		}
		
		cout << "\t       GAME OVER\n\n\n\n"
			 << "\t      Player 1: " << cont1 << endl
			 << "\t      Player 2: " << cont2 << "\n\n"
			 << "\t   Ball Speed: ";
		
		if(freq == 40)
		{
			cout << "Slow";
		}
		else if(freq == 25)
		{
			cout << "Medium";
		}
		else
		{
			cout << "Fast";
		}
		
		cout <<"\n\n\n\n"
			 << "\t     Continue (C) ?\n"
			 << "\t   Reset Scores (R) ?\n"
			 << "\t Change Ball Speed (S) ?\n\n"
			 << "\t     'Esc' to Exit";
		
		while(!ans2)
		{
			if(GetAsyncKeyState(K_C))
			{
				ans1 = true;
				ans2 = true;
			}
			
			if(GetAsyncKeyState(K_R))
			{
				cont1 = 0;
				cont2 = 0;
				
				ans2 = true;
			}
			
			if(GetAsyncKeyState(K_S))
			{
				difficulty(freq, close);
				
				if(close)
				{
					ans1 = true;
				}
				
				ans2 = true;
			}
			
			if(GetAsyncKeyState(K_Esc))
			{
				close = true;
				ans1 = true;
				ans2 = true;
			}
		}
		
		clearBufer();
	}
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void openingSong()
{
	//	G G2 G A2 G B2 G2 G G2
	
	Beep(392, 250);
	Beep(784, 250);
	Beep(392, 250);
	Beep(880, 250);
	Beep(392, 250);
	Beep(988, 250);
	Beep(784, 250);
	Beep(392, 250);
	Beep(784, 250);
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void gameOverSong()
{
	//	D2 D2 A2 D2 G2 D2 F2 D2
	
	Beep(587, 250);
	Beep(587, 250);
	Beep(880, 250);
	Beep(587, 250);
	Beep(784, 250);
	Beep(587, 250);
	Beep(699, 250);
	Beep(587, 250);
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void clearBufer()
{
	HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void printVoid()
{
	for(int i = 0; i < 40; i++) cout << endl;
}