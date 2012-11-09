/*
       ==========================================
       ||                                      ||
       ||            Source coded by:          ||
       ||      Carlos Aguilar de la Morena     ||
       ||                                      ||
       ||           At  4 / 11 / 2012          ||
       ||                                      ||
       ==========================================
*/

//Libraries
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

//Main Function
int main()
{
	int CPU;
	char user;

	srand(time(NULL));

	cout << "\n\tRock, Paper, Scissors !!!\n\n"
		 << "Type 'Exit' whenever you want to quit the game\n"
		 << "===================================================\n\n"
		 << "You ===> ";
	cin >> user;

	while(user != 'E' && user != 'e' && user != 'R' && user != 'r' && user != 'P' && user != 'p' && user != 'S' && user != 's')
	{
		cout << "Error\nYou ===> ";
		cin >> user;
	}

	while(user != 'E' && user != 'e')
	{
		CPU = (rand() % 3);

		if(CPU == 0)
		{
			cout << "CPU ===> Rock\n\n";

			if(user == 'R' || user == 'r')
			{
				cout << "\t Draw";
			}
			else if(user == 'P' || user == 'p')
			{
				cout << "\t You Win";
			}
			else
			{
				cout << "\t You Lose";
			}
		}
		else if(CPU == 1)
		{
			cout << "CPU ===> Paper\n\n";

			if(user == 'R' || user == 'r')
			{
				cout << "\t You Lose";
			}
			else if(user == 'P' || user == 'p')
			{
				cout << "\t Draw";
			}
			else
			{
				cout << "\t You Win";
			}
		}
		else
		{
			cout << "CPU ===> Scissors\n\n";

			if(user == 'R' || user == 'r')
			{
				cout << "\t You Win";
			}
			else if(user == 'P' || user == 'p')
			{
				cout << "\t You Lose";
			}
			else
			{
				cout << "\t Draw";
			}
		}

		cout << "\n\n===================================================\n\n"
			 << "You ===> ";
		cin >> user;

		while(user != 'E' && user != 'e' && user != 'R' && user != 'r' && user != 'P' && user != 'p' && user != 'S' && user != 's')
		{
			cout << "Error\nYou ===> ";
			cin >> user;
		}

	}

	return 0;
}
