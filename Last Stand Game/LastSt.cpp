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
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	int obj, turn, move;

	//Seleccion de Turno
	srand(time(NULL));
	if((rand() % 2) == 0)
	{
		turn = 1;
	}
	else
	{
		turn = 2;
	}

	//Bienvenida, reglas y preparacion.
	cout << "\n\tBienvenido\n\n"
		 << "==========================\n\n"
		 << "Reglas del juego:\n"
		 << "El jugador define un numero determinado de objetos.\n"
		 << "La CPU decide quien empieza y, por turnos, la CPU y\n"
		 << "el jugador van retirando objetos. El numero de objetos\n"
		 << "que se pueden retirar en cada turno es de 1, 2 o 3.\n"
		 << "El que retire el ultimo objeto, pierde.\n\n"
		 << "==========================\n\n"
		 << "Defina el numero de objetos en esta partida: ";
	cin >> obj;
	cout << "Empieza la partida ";

	if(turn == 1)
	{
		cout << "el jugador.\n";
	}
	else
	{
		cout << "la CPU.\n";
	}

	//Comienza el juego
	while(obj > 0)
	{
		cout << "\n==========================\n\n"
			 << "Objetos restantes: " << obj << endl;

		//Turno jugador
		if(turn == 1)
		{
			cout << "Cuantos objetos desea retirar? ";
			cin >> move;

			//Error de movimiento
			while((move < 1) || (3 < move))
			{
				cout << "Solo se pueden retirar 1, 2 o 3 objetos por turno.\n"
					 << "Cuantos objetos desea retirar? ";
				cin >> move;
			}

			obj -= move;
			turn = 2;
		}
		//Turno CPU
		else
		{
			//Seleccion de movimiento
			if(obj >= 3)
			{
				move = (rand() % 3);
				
				if(move == 0)
				{
					cout << "La maquina retira 1 objeto.\n";
					obj -= 1;
				}
				else if(move == 1)
				{
					cout << "La maquina retira 2 objetos.\n";
					obj -= 2;
				}
				else
				{
					cout << "La maquina retira 3 objetos.\n";
					obj -= 3;
				}
			}
			else if(obj == 2)
			{
				move = (rand() % 2);
				
				if(move == 0)
				{
					cout << "La maquina retira 1 objeto.\n";
					obj -= 1;
				}
				else
				{
					cout << "La maquina retira 2 objetos.\n";
					obj -= 2;
				}
			}
			else
			{
				cout << "La maquina retira 1 objeto.\n";
				obj -= 1;
			}

			turn = 1;
		}
	}

	cout << "\n==========================\n\n";

	if(turn == 1)
	{
		cout << "\nEnhorabuena! Has ganado\n\n"
			 << "==========================\n\n";
	}
	else
	{
		cout << "\nGame Over, gana la CPU\n\n"
			 << "==========================\n\n";
	}

	system("pause");
	return 0;
}
