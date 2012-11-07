/*
       ==========================================
       ||                                      ||
       ||            Source coded by:          ||
       ||      Carlos Aguilar de la Morena     ||
       ||                                      ||
       ||           At  1 / 11 / 2012          ||
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
    int lim_inf, lim_sup, range, var;
    char user('a');

    //Determinacion de limites
    cout << "Piense un numero en un rango determinado.\n"
    	 << "Introduzca el limite inferior: ";
    cin >> lim_inf;
    cout << "Introduzca el limite superior: ";
    cin >> lim_sup;

    //Calculo semilla rand()
    srand(time(NULL));

    //Comienza el juego
    while(user != '=')
    {
		//Calculo longitud del rango (Limites incluidos: Diferencia +1)
		range = lim_sup - lim_inf + 1;
		
    	//Variable dentro del rango
    	var = ((int(rand()) % range) + lim_inf);

    	cout << "Es este su numero? " << var << endl
    		 << "Introduzca '<', '>' o '=', segun aplique: ";
    	cin >> user;

    	//Input y asignacion de limites nuevos
    	if(user == '<')
    		lim_sup = var - 1;
    	if(user == '>')
    		lim_inf = var + 1;
    }

    //Fin
    cout << "\nGame Over\n\n";

    system("pause");
	return 0;
}
