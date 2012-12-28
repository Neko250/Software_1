#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
using namespace std;

#include "VK.cpp"

//===================================================

const int freq = 100;

void print(int);

//===================================================

int main()
{
	system("mode con: lines=14 cols=28");
	
	int counter = 0;
	bool run = true;
	
	print(counter);
	
	while(run)
	{
		if(GetAsyncKeyState(VK_Esc))
		{
			run = false;
		}
		
		if(GetAsyncKeyState(VK_Num1) || GetAsyncKeyState(VK_Space) || GetAsyncKeyState(VK_NumPlus))
		{
			counter++;
			if(counter > 99999999) counter = 99999999;
			print(counter);
			Sleep(freq);
		}
		
		if(GetAsyncKeyState(VK_Num2))
		{
			counter += 2;
			if(counter > 99999999) counter = 99999999;
			print(counter);
			Sleep(freq);
		}
		
		if(GetAsyncKeyState(VK_Num3))
		{
			counter += 3;
			if(counter > 99999999) counter = 99999999;
			print(counter);
			Sleep(freq);
		}
		
		if(GetAsyncKeyState(VK_Num4))
		{
			counter += 4;
			if(counter > 99999999) counter = 99999999;
			print(counter);
			Sleep(freq);
		}
		
		if(GetAsyncKeyState(VK_Num5))
		{
			counter += 5;
			if(counter > 99999999) counter = 99999999;
			print(counter);
			Sleep(freq);
		}
		
		if(GetAsyncKeyState(VK_Num6))
		{
			counter += 6;
			if(counter > 99999999) counter = 99999999;
			print(counter);
			Sleep(freq);
		}
		
		if(GetAsyncKeyState(VK_Num7))
		{
			counter += 7;
			if(counter > 99999999) counter = 99999999;
			print(counter);
			Sleep(freq);
		}
		
		if(GetAsyncKeyState(VK_Num8))
		{
			counter += 8;
			if(counter > 99999999) counter = 99999999;
			print(counter);
			Sleep(freq);
		}
		
		if(GetAsyncKeyState(VK_Num9))
		{
			counter += 9;
			if(counter > 99999999) counter = 99999999;
			print(counter);
			Sleep(freq);
		}
		
		if(GetAsyncKeyState(VK_Num0))
		{
			counter += 10;
			if(counter > 99999999) counter = 99999999;
			print(counter);
			Sleep(freq);
		}
		
		if(GetAsyncKeyState(VK_Return) || GetAsyncKeyState(VK_Backspace))
		{
			counter = 0;
			print(counter);
			Sleep(freq);
		}
	}
	
	return 0;
}

//===================================================

void print(int counter)
{
	system("cls");
	
	cout << endl
		 << "         __________" << endl
		 << "    ..--'          '--.." << endl
		 << "   /  ________________  \\" << endl
		 << "  |  |                |  |" << endl
		 << "  |  |                |  |" << endl
		 << "  |  |    ";
	
	if(counter < 10) cout << "       ";
	else if(counter < 100) cout << "      ";
	else if(counter < 1000) cout << "     ";
	else if(counter < 10000) cout << "    ";
	else if(counter < 100000) cout << "   ";
	else if(counter < 1000000) cout << "  ";
	else if(counter < 10000000) cout << " ";
	
	cout << counter << "    |  |" << endl
		 << "  |  |                |  |" << endl
		 << "  |  |________________|  |" << endl
		 << "  |______________________|" << endl
		 << "  |          ||          |" << endl
		 << "   \\     +1  ||  0      /" << endl
		 << "    ''--.____||____.--''" << endl;
}