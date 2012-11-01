/*
       ==========================================
       ||                                      ||
       ||            Source coded by:          ||
       ||      Carlos Aguilar de la Morena     ||
       ||                                      ||
       ||           At  30 / 10 / 2012         ||
       ||                                      ||
       ==========================================
*/

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int lim_inf, lim_sup, var;
    char user('a');

    cout << "Piense un numero en un rango determinado.\n"
    	 << "Introduzca el limite inferior: ";
    cin >> lim_inf;
    cout << "Introduzca el limite superior: ";
    cin >> lim_sup;

    srand(time(NULL));

    while(user != '=')
    {
    	do
    	{
    		var = ((rand()) % (lim_sup));
    	}
    	while(var <= lim_inf);

    	cout << "Es este su numero? " << var << endl
    		 << "Introduzca '<', '>' o '=', segun aplique: ";
    	cin >> user;

    	if(user == '<')
    		lim_sup = var;
    	if(user == '>')
    		lim_inf = var;
    }

    cout << "\nGame Over\n\n";

    system("pause");
	return 0;
}
