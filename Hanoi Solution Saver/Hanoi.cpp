//
//	Coded By Carlos Aguilar de la Morena
//

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <fstream>
using namespace std;

void hanoi(int, string, string, string);
void hanoi_sav(int, string, string, string, ofstream&);

int main()
{
	//	Declaracion, apertura y error de flujo
	
	ofstream solution;
	
	solution.open("solution.txt");
	if(solution.fail())
	{
		cout << "\n\tError al abrir el archivo \"solution.txt\"";
		Sleep(2000);
		return 0;
	}
	
	//----------------------------------------------------------------
	
	int n;
	
	cout << "\nIntroduzca el numero de pisos de la torre de Hanoi: ";
	cin >> n;
	cout << "\nLa solucion a la torre dada ([(2^n)-1] pasos):\n\n";
	hanoi(n, "1", "3", "2");
	
	solution << "Numero de pisos de la torre: " << n << endl << endl
		   << "Solucion, [(2^n)-1] pasos:\n\n";
	hanoi_sav(n, "1", "3", "2", solution);
	solution.close();
	
	cout << "\n\nSolucion guardada exitosamente en \"solution.txt\"\n\n";
	system("pause");
	
	return 0;
}

//=====================================================================================
//
//	Hanoi Solver

void hanoi(int n, string desde, string hasta, string ayuda)
{
    if (n == 1)
	{
        cout << "(" << desde << "-" << hasta << ")\n";
    }
	else
	{
        hanoi(n - 1, desde, ayuda, hasta);
        cout << "(" << desde << "-" << hasta << ")\n";
        hanoi(n - 1, ayuda, hasta, desde);
    }
}

//=====================================================================================
//
//	Hanoi Solution Saver

void hanoi_sav(int n, string desde, string hasta, string ayuda, ofstream& solution)
{
    if (n == 1)
	{
        solution << "(" << desde << "-" << hasta << ")\n";
    }
	else
	{
        hanoi_sav(n - 1, desde, ayuda, hasta, solution);
        solution << "(" << desde << "-" << hasta << ")\n";
        hanoi_sav(n - 1, ayuda, hasta, desde, solution);
    }
}