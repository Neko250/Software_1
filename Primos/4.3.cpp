/*
       ==========================================
       ||                                      ||
       ||            Source coded by:          ||
       ||      Carlos Aguilar de la Morena     ||
       ||                                      ||
       ||           At  26 / 11 / 2012         ||
       ||                                      ||
       ==========================================
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

void welcome(int&);
void print(int);
bool primo(int);

int main()
{
	int N, cont = 1;
	
	welcome(N);
	print(N);
	
	return 0;
}

//=================================================================
//
//	Bienvenida y peticion de N

void welcome(int& N)
{
	cout << "\n\tBienvenido\n\n"
		 << "Introduzca un numero entero 'N': ";
	cin >> N;
	cout << "Los primeros " << N << " primos son:\n\n";
}

//=================================================================
//
//	Salida por pantalla

void print(int N)
{
	int cont = 0, num = 1;
	
	while(cont < N)
	{
		if(primo(num))
		{
			cout << num << " ";
			cont++;
		}
		
		num++;
	}
	
	cout << endl << endl;
	system("pause");
}

//=================================================================
//
//	Dice si un numero es primo o no

bool primo(int N)
{
	bool primo = true;
	for(int divisor = 2; divisor <= sqrt(N); divisor++)
	{
		if(N % divisor == 0)
		{
			primo = false;
		}
	}

	return primo;
}