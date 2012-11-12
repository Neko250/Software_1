
// Coded by Carlos Aguilar de la Morena

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
using namespace std;

void welcome(int&);
int random();
void strobo(int, int);

int main()
{
	int freq;

	welcome(freq);
	while(1 > 0)
	{
		strobo(random(), freq);
	}
	return 0;
}

//=======================================================

void welcome(int& freq)
{
	cout << "\n\tWelcome\n"
		 << "\tPress \"Ctrl+C\" to exit.\n"
		 << "=======================================\n\n"
		 << "Type in the stroboscopic light frequency in milliseconds: ";
	cin >> freq;
	cout << "\n=======================================\n\n";
	system("pause");
	system("cls");
}

//=======================================================

int random()
{
	return rand() % 16;
}

//=======================================================

void strobo(int num, int freq)
{
	switch(num)
	{
		case 0:
			system("color 00");
			Sleep(freq);
			break;
		case 1:
			system("color 10");
			Sleep(freq);
			break;
		case 2:
			system("color 20");
			Sleep(freq);
			break;
		case 3:
			system("color 30");
			Sleep(freq);
			break;
		case 4:
			system("color 40");
			Sleep(freq);
			break;
		case 5:
			system("color 50");
			Sleep(freq);
			break;
		case 6:
			system("color 60");
			Sleep(freq);
			break;
		case 7:
			system("color 70");
			Sleep(freq);
			break;
		case 8:
			system("color 80");
			Sleep(freq);
			break;
		case 9:
			system("color 90");
			Sleep(freq);
			break;
		case 10:
			system("color A0");
			Sleep(freq);
			break;
		case 11:
			system("color B0");
			Sleep(freq);
			break;
		case 12:
			system("color C0");
			Sleep(freq);
			break;
		case 13:
			system("color D0");
			Sleep(freq);
			break;
		case 14:
			system("color E0");
			Sleep(freq);
			break;
		case 15:
			system("color F0");
			Sleep(freq);
			break;
		default:
			cout << "ERROR";
			break;
	}

}