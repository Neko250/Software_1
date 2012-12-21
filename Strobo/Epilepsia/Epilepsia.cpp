// Coded by Carlos Aguilar de la Morena

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
using namespace std;

#define VK_Esc 27
#define VK_Space 32
#define VK_M 77
#define VK_I 73
#define VK_O 79

void welcome(int&, bool&);
void strobo(int&, int);
void getKey(bool&, bool&, bool&, bool&);
void clearBufer();

int main()
{
	int num(1), freq;
	
	bool menu = true, run1 = true, run2 = false, quit = false;
	
	system("mode con: lines=50 cols=150");
	
	while(!quit)
	{
		if(menu)
		{
			welcome(freq, menu);
		}
		
		run1 = true;
		
		while(run1)
		{
			system("color 07");
			
			getKey(menu, run1, run2, quit);
		}
		
		while(run2)
		{
			strobo(num, freq);
			getKey(menu, run1, run2, quit);
		}
	}
	
	return 0;
}

//=======================================================

void welcome(int& freq, bool& menu)
{
	system("cls");
	system("color 07");
	
	clearBufer();
	
	for(int i = 0; i < 20; i++)
	{
		cout << endl;
	}
	
	cout << "\t\t\t\t\t\t              Welcome\n\n"
		 << "\t\t\t\t\t\t         Press \"Esc\" to exit.\n"
		 << "\t\t\t\t\t\t         Press \"M\" for menu.\n"
		 << "\t\t\t\t\t\t         Press \"I\" for ON\n"
		 << "\t\t\t\t\t\t         Press \"O\" for OFF\n\n"
		 << "\t\t\t\t\t\t=======================================\n\n"
		 << "\t\t\t\t\t\t      Frequency in milliseconds: ";
	cin >> freq;
	
	menu = false;
	
	system("cls");
}

//=======================================================

void strobo(int& num, int freq)
{	
	switch(num)
	{
		case 0:
			system("color 70");
			num = 1;
			Sleep(freq);
			break;
		case 1:
			system("color 07");
			num = 0;
			Sleep(freq);
			break;
		default:
			cout << "ERROR";
			break;
	}

}

//=======================================================

void getKey(bool& menu, bool& run1, bool& run2, bool& quit)
{
	if(GetAsyncKeyState(VK_Esc))
	{
		run1 = false;
		run2 = false;
		menu = false;
		quit = true;
	}
	
	if(GetAsyncKeyState(VK_I))
	{
		run1 = false;
		run2 = true;
		menu = false;
	}
	
	if(GetAsyncKeyState(VK_O))
	{
		run1 = true;
		run2 = false;
		menu = false;
	}
	
	if(GetAsyncKeyState(VK_M))
	{
		run1 = false;
		run2 = false;
		menu = true;
	}
}

//=======================================================

void clearBufer()
{
	HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
}