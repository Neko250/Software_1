#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

//===========================================
//==============              ===============
//==============  Prototipos  ===============
//==============              ===============
//===========================================

void welcome();
void menu(int&);
void selection(bool&, int);

void ayuda();
void producto();
void potencia();
void factorial();
void combinatorio();
void secuencial();
void funcionesAB();
void permutaciones();
void permGener();
void combinaciones();
void combRepet();
void sobreyectiva();
void stirling();

//===========================================
//                Operaciones              //
//===========================================

int fact(int);
int comb(int, int);
int pow(int, int);
int stir(int, int);

//==================================================
//
//	Principal

int main()
{
	bool end = false;
	int sel;
	
	welcome();
	
	while(!end)
	{
		menu(sel);
		selection(end, sel);
	}
	
	return 0;
}

//==================================================
//                   Bienvenida                   //
//==================================================

void welcome()
{
	//system("mode con:cols=80 lines=27");
	system("color 0A");
	system("title TDR Calc");
	system("cls");
	cout << endl << endl
		 << "\t _ _ _\n"
		 << "\t| | | |\n"
		 << "\t| | | |\n"
		 << "\t|_____|";
	Sleep(500);
	system("cls");
	cout << endl << endl
		 << "\t _ _ _\n"
		 << "\t| | | |___\n"
		 << "\t| | | | -_|\n"
		 << "\t|_____|___|";
	Sleep(500);
	system("cls");
	cout << endl << endl
		 << "\t _ _ _     _\n"
		 << "\t| | | |___| |\n"
		 << "\t| | | | -_| |\n"
		 << "\t|_____|___|_|";
	Sleep(500);
	system("cls");
	cout << endl << endl
		 << "\t _ _ _     _\n"
		 << "\t| | | |___| |___\n"
		 << "\t| | | | -_| |  _|\n"
		 << "\t|_____|___|_|___|";
	Sleep(500);
	system("cls");
	cout << endl << endl
		 << "\t _ _ _     _\n"
		 << "\t| | | |___| |___ ___\n"
		 << "\t| | | | -_| |  _| . |\n"
		 << "\t|_____|___|_|___|___|";
	Sleep(500);
	system("cls");
	cout << endl << endl
		 << "\t _ _ _     _\n"
		 << "\t| | | |___| |___ ___ _____\n"
		 << "\t| | | | -_| |  _| . |     |\n"
		 << "\t|_____|___|_|___|___|_|_|_|";
	Sleep(500);
	system("cls");
	cout << endl << endl
		 << "\t _ _ _     _\n"
		 << "\t| | | |___| |___ ___ _____ ___\n"
		 << "\t| | | | -_| |  _| . |     | -_|\n"
		 << "\t|_____|___|_|___|___|_|_|_|___|";
	Sleep(2000);
}

//==================================================
//                      Heart                     //
//==================================================

void menu(int& sel)
{
	do
	{
		system("cls");
		cout << endl << endl
			 << "\t _____                     _\n"
			 << "\t| __  |___ ___ _ _ ___ ___| |_ ___\n"
			 << "\t|    -| -_|  _| | | -_|   |  _| . |\n"
			 << "\t|__|__|___|___|___|___|_|_|_| |___|\n\n"
			 << "\tSeleccione el modo:\n\n"
			 << "\tAyuda =================> 0\n"
			 << "\tProducto ==============> 1\n"
			 << "\tPotencia ==============> 2\n"
			 << "\tFactorial =============> 3\n"
			 << "\tNumero Combinatorio ===> 4\n"
			 << "\tRecuento Secuencial ===> 5\n"
			 << "\tFunciones de A en B ===> 6\n"
			 << "\tPermutaciones =========> 7\n"
			 << "\tPerm. Generalizadas ===> 8\n"
			 << "\tCombinaciones =========> 9\n"
			 << "\tComb. Repeticion ======> 10\n"
			 << "\tFuncion Sobreyectiva ==> 11\n"
			 << "\tNumero de Stirling ====> 12\n"
			 << "\tSalir =================> 13\n\n"
			 << "\tSeleccion: ";
		cin >> sel;
		
		if(sel < 0 || sel > 13)
		{
			cout << "\n\tERROR: Seleccion Invalida.";
			Sleep(1000);
		}
	}
	while(sel < 0 || sel > 13);
}

//==================================================
//                    Seleccion                   //
//==================================================

void selection(bool& end, int sel)
{
	system("cls");
	
	switch(sel)
	{
		case 0:
			ayuda();
			break;
		
		case 1:
			producto();
			break;
		
		case 2:
			potencia();
			break;
		
		case 3:
			factorial();
			break;
		
		case 4:
			combinatorio();
			break;
		
		case 5:
			secuencial();
			break;
		
		case 6:
			funcionesAB();
			break;
		
		case 7:
			permutaciones();
			break;
		
		case 8:
			permGener();
			break;
		
		case 9:
			combinaciones();
			break;
		
		case 10:
			combRepet();
			break;
		
		case 11:
			sobreyectiva();
			break;
		
		case 12:
			stirling();
			break;
		
		case 13:
			end = true;
			break;
	}
}

//==================================================
//
//	AYUDA

void ayuda()
{
	cout << "\n\n"
		 << "\tRecuento Elemental: Modelo de Seleccion\n"
		 << "\t==========================================================\n"
		 << "\tManeras de seleccionar 'r' elementos de un conjunto de 'n'\n\n"
		 << "\t- Permutacion P(n, r):\n"
		 << "\tElementos distintos, el orden influye\n"
		 << "\t- Combinacion C(n, r):\n"
		 << "\tElementos distintos, el orden no influye\n"
		 << "\t- n^r:\n"
		 << "\tElementos indistinguibles, el orden influye\n"
		 << "\t- Comb. Repeticion CR(n, r):\n"
		 << "\tElementos indistinguibles, orden no influye\n\n"
		 << "\tRecuento Elemental: Modelo de Asignacion\n"
		 << "\t==========================================================\n"
		 << "\tManeras de asignar 'r' objetos a 'n' posiciones\n\n"
		 << "\t- Permutacion P(n, r):\n"
		 << "\tObjetos distintos, cada posicion 1 objeto\n"
		 << "\t- Combinacion C(n, r):\n"
		 << "\tObjetos identicos, cada posicion 1 objeto\n"
		 << "\t- n^r:\n"
		 << "\tObjetos distintos, cada posicion 1+ objetos\n"
		 << "\t- Comb. Repeticion CR(n, r):\n"
		 << "\tObjetos identicos, cada posicion 1+ objetos\n\n"
		 << "\tFunciones\n"
		 << "\t==========================================================\n\n"
		 << "\tAplicaciones ---> n^r\n"
		 << "\tInyectiva ------> n(n-1)(n-2)...(n-r+1)\n"
		 << "\tBiyectiva ------> n!\n"
		 << "\tSobreyectiva ---> n! * S(r, n)\n\n\t";
	
	system("pause");
}

//==================================================
//
// Producto

void producto()
{
	int user, tot, ans = 1;
	
	cout << "\n\n\tProducto\n\t========\n\n"
		 << "\tIntroduzca el numero de factores del producto: ";
	cin >> tot;
	cout << endl;
	
	for(int i = 1; i <= tot; i++)
	{
		cout << "\tFactor " << i << ": ";
		cin >> user;
		ans *= user;
	}
	
	cout << "\n\tResultado: " << ans << "\n\n\t";
	system("pause");
}

//==================================================
//
//	Potencia

void potencia()
{
	int base, exponente;
	
	cout << "\n\n\tPotencia\n\t========\n\n"
		 << "\tIntroduzca la base: ";
	cin >> base;
	cout << "\tIntroduzca el exponente: ";
	cin >> exponente;
	cout << "\n\tResultado: " << pow(base, exponente) << "\n\n\t";
	system("pause");
}

//==================================================
//
//	Factorial

void factorial()
{
	int num;
	
	cout << "\n\n\tFactorial\n\t=========\n\n"
		 << "\tIntroduzca el numero: ";
	cin >> num;
	cout << "\n\tResultado: " << fact(num) << "\n\n\t";
	system("pause");
}

//==================================================
//
//	Combinatorio

void combinatorio()
{
	int sup, inf;
	
	cout << "\n\n\tNumero combinatorio\n\t===================\n\n"
		 << "\tIntroduzca el numero superior: ";
	cin >> sup;
	cout << "\tIntroduzca el numero inferior: ";
	cin >> inf;
	cout << "\n\tResultado: " << comb(sup, inf) << "\n\n\t";
	system("pause");
}

//==================================================
//
//	Secuencial

void secuencial()
{
	int elem, posic, ans = 1;
	
	cout << "\n\n\tRecuento Secuencial\n\t===================\n\n"
		 << "\tIntroduzca el numero de elementos: ";
	cin >> elem;
	cout << "\tIntroduzca el numero de posiciones: ";
	cin >> posic;
	
	for(int i = 1; i <= posic; i++)
	{
		ans *= elem;
		elem--;
	}
	
	cout << "\n\tResultado: " << ans << "\n\n\t";
	system("pause");
}

//==================================================
//
//	Funciones A en B

void funcionesAB()
{
	int elemA, elemB;
	
	cout << "\n\n\tFunciones definibles de A en B\n\t==============================\n\n"
		 << "\tIntroduzca el numero de elementos de A: ";
	cin >> elemA;
	cout << "\tIntroduzca el numero de elementos de B: ";
	cin >> elemB;
	cout << "\n\tResultado: " << pow(elemB, elemA) << "\n\n\t";
	system("pause");
}

//==================================================
//
//	Permutaciones

void permutaciones()
{
	int r, n, ans;
	
	cout << "\n\n\tPermutaciones\n\t=============\n\n"
		 << "\tP(n, r) : r-permutaciones de un conjunto de 'n' elementos\n\n"
		 << "\tIntroduzca el numero de elementos del conjunto, 'n': ";
	cin >> n;
	cout << "\tIntroduzca el numero de elementos de la permutacion, 'r': ";
	cin >> r;
	
	ans = fact(n) / fact(n-r);
	
	cout << "\n\tResultado: " << ans << "\n\n\t";
	system("pause");
}

//==================================================
//
//	Permutaciones Generalizadas

void permGener()
{
	int n, k, nk, ans;
	
	cout << "\n\n\tPermutaciones Generalizadas\n\t===========================\n\n"
		 << "\tColeccion de 'n' objetos de 'k' tipos diferentes\n\n"
		 << "\tIntroduzca el numero de elementos de la permutacion, 'n': ";
	cin >> n;
	cout << "\tIntroduzca el numero de tipos de objetos, 'k': ";
	cin >> k;
	
	ans = fact(n);
	
	for(int i = 1; i <= k; i++)
	{
		cout << "\t- Introduzca el numero de objetos del tipo " << i << ": ";
		cin >> nk;
		ans /= fact(nk);
	}
	
	cout << "\n\tResultado: " << ans << "\n\n\t";
	system("pause");
}

//==================================================
//
//	Combinaciones

void combinaciones()
{
	int n, r;
	
	cout << "\n\n\tCombinaciones\n\t=============\n\n"
		 << "\tC(n, r) : subconjunto de 'r' elementos de un conjunto de 'n'\n\n"
		 << "\tIntroduzca el numero de elementos del conjunto, 'n': ";
	cin >> n;
	cout << "\tIntroduzca el numero de elementos de la combinacion, 'r': ";
	cin >> r;
	cout << "\n\tResultado: " << comb(n, r) << "\n\n\t";
	system("pause");
}

//==================================================
//
//	Combinaciones con Repeticion

void combRepet()
{
	int n, r;
	
	cout << "\n\n\tCombinaciones con Repeticion\n\t============================\n\n"
		 << "\tCR(n, r) : subconjunto de 'r' elementos de un conjunto de 'n'\n"
		 << "\tLos elementos de la combinacion se pueden repetir\n\n"
		 << "\tIntroduzca el numero de elementos del conjunto, 'n': ";
	cin >> n;
	cout << "\tIntroduzca el numero de elementos de la combinacion, 'r': ";
	cin >> r;
	cout << "\n\tResultado: " << comb((n+r-1), r) << "\n\n\t";
	system("pause");
}

//==================================================
//
//	Funcion Sobreyectiva

void sobreyectiva()
{
	int elemA, elemB, ans;
	
	cout << "\n\n\tFunciones Sobreyectivas de A en B\n\t=================================\n\n"
		 << "\tIntroduzca el numero de elementos de A: ";
	cin >> elemA;
	cout << "\tIntroduzca el numero de elementos de B: ";
	cin >> elemB;
	
	ans = fact(elemB) * stir(elemA, elemB);
	
	cout << "\n\tResultado: " << ans << "\n\n\t";
	system("pause");
}

//==================================================
//
//	Stirling

void stirling()
{
	int r, n;
	
	cout << "\n\n\tNumero de Stirling\n\t============================\n\n"
		 << "\tS(r, n) : maneras de distribuir 'r' objetos en 'n' contenedores\n"
		 << "\tNingun contenedor se queda vacio\n\n"
		 << "\tIntroduzca el numero de elementos a distribuir, 'r': ";
	cin >> r;
	cout << "\tIntroduzca el numero de contenedores, 'n': ";
	cin >> n;
	cout << "\n\tResultado: " << stir(r, n) << "\n\n\t";
	system("pause");
}

//--------------------------------------------------
//
//	Factorial OPERACION

int fact(int x)
{
	int ans = 1;
	
	if(x > 0)
	{
		for(int i = 1; i <= x; i++)
		{
			ans *= i;
		}
	}
	
	return ans;
}

//--------------------------------------------------
//
//	Combinatorio OPERACION

int comb(int a, int b)
{
	int ans = 1;
	
	if(0 < b && b < a)
	{
		ans = (fact(a) / (fact(b) * fact(a-b)));
	}
	
	return ans;
}

//--------------------------------------------------
//
//	Potencia OPERACION

int pow(int a, int b)
{
	int ans = 1;
	
	if(b > 0)
	{
		for(int i = 1; i <= b; i++)
		{
			ans *= a;
		}
	}
	
	return ans;
}

//--------------------------------------------------
//
//	Calculo del numero de Stirling OPERACION

int stir(int r, int n)
{
	int ans = 0;
	
	for(int count = 0; count < n; count++)
	{
		ans += pow(-1, count) * pow((n - count), r) * comb(n, count);
	}
	
	ans /= fact(n);
	
	return ans;
}
