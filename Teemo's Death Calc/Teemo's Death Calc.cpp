/*
       ==========================================
       ||                                      ||
       ||          Programa creado por:        ||
       ||      Carlos Aguilar de la Morena     ||
       ||                                      ||
       ||           El  25 / 10 / 2012         ||
       ||                                      ||
       ==========================================
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

const int HORA(3600);
const int MIN(60);
const int DEAD(75);

int main()
{
	int hora, min, seg, time, teemos;
	
	cout << "\n\tBienvenido a la calculadora de Teemos Muertos\n\n"
		 << "Introduzca la hora del dia,\n"
		 << "en horas, minutos y segundos:\n";
	cin >> hora >> min >> seg;
	
	time = ((hora * HORA) + (min * MIN) + seg);
	teemos = time * DEAD;
	
	cout << "\nSiendo la hora introducida: " << hora << ":" << min << ":" << seg
		 << "\nla cantidad de Teemos muertos es:\n\n\t" << teemos
		 << "\n\n";
	
	system("pause");
	return 0;
}