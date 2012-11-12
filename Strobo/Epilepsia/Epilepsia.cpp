
// Coded by Carlos Aguilar de la Morena

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
using namespace std;

void welcome(int&);
void strobo(int&, int);

int main()
{
	int num(1), freq;

	welcome(freq);
	while(1 > 0)
	{
		strobo(num, freq);
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