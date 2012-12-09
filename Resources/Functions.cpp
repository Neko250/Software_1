#include "header.h"
using namespace std;

//=======================================================
//
//	Da un numero aleatorio entre [0, num - 1]

int random(int num)
{
	srand(time(NULL));
	
	return (rand() % num);
}

//=======================================================
//
//	Calcula si en 'n' en binario existe, al menos, un grupo de 'k' 1s

bool k_ones_in_n(unsigned k, unsigned n)
{
	unsigned count(0);
	for(; (n != 0) && (count != k); n /= 2)
	{
		if(n % 2 == 1)
		{
			count++;
		}
		else
		{
			count = 0;
		}
	}
	return (count == k);
}

//=======================================================
//
//	Calcula la fuerza gravitatoria entre dos cuerpos (Pide masas y distancia)(Dinas)

double gravity(double m1, double m2, double d)
{
	double G = 0.00000006673;

	return ((G * m1 * m2) / (d * d));
}

//=======================================================
//
//	Imprime solucion Torre de Hanoi

void hanoi(int n, char from, char use, char to)
{
    hanoi(n-1, from, to, use);
    cout << "(" << from << " - " << to << ")";
    hanoi(n-1, use, from, to);
}

//=======================================================
//
//	Potencia

int pow(int a, int b)
{
	int ans(1);

	for(int i = 1; i <= b; i++)
	{
		ans *= a;
	}

	return ans;
}

//==========================================================
//
//	Factorial

double fact(double X)
{
	double ans = 1;
	
	for(int i = 1; i <= X; i++)
	{
		ans *= i;
	}
	
	return ans;
}

//=======================================================
//
//	Numero de digitos de 'N'

unsigned digits(unsigned N)
{
	unsigned digits(1);

	for(unsigned mod = 10; (N / mod) != 0; mod *= 10)
	{
		digits++;
	}

	return digits;
}

//=======================================================
//
//	Calcula el digito en la posicion i-esima de 'N'

unsigned pos_calc(unsigned N, unsigned i)
{
	unsigned position;

	position = (N / pow(10, (i - 1))) % 10;
	return position;
}

//=======================================================
//
//	Muestra si un numero es primo o no

bool prime(unsigned N)
{
	bool prime = true;
	for(unsigned divisor = 2; divisor < N; divisor++)
	{
		if(N % divisor == 0)
		{
			prime = false;
		}
	}

	return prime;
}

//=======================================================
//
//	Dibuja un triangulo de base y altura 'n'

void triangle(unsigned n)
{
	for(unsigned fila(1); fila <= n; fila++)
	{
		cout << "\t";
		spaces(fila, n);
		draw(fila);
		cout << endl;
	}
}

//-------------------------------------------------------

void spaces(unsigned fila, unsigned n)
{
	for(unsigned i(1); i <= (n - fila); i++)
	{
		cout << " ";
	}
}

//-------------------------------------------------------

void draw(unsigned fila)
{
	for(unsigned i(1); i <= ((2 * fila) - 1); i++)
	{
		if(i % 2 == 1)
		{
			cout << "*";
		}
		else
		{
			cout << " ";
		}
	}
}

//=======================================================
//
//	Guardar texto en un archivo

void save_text()
{
	ofstream output;
	output.open("file.txt");
	char text(' ');

	system("cls");
	cout << endl;
	cout << "Introduzca un texto, acabado en una barra espaciadora\n"
		 << "invertida para indicar el final del texto, y pulse enter:\n\n";

	while(text != '\\')
	{
		cin.get(text);
		output << text;
	}

	system("cls");
	cout << endl;
	cout << "\nSu archivo se ha guardado exitosamente.";
	Sleep(1500);
}

//=======================================================
//
//	Mostrar texto de un archivo

void load_text()
{
	ifstream input;
	input.open("file.txt");
	char text(' ');

	system("cls");
	cout << endl;
	cout << "Texto guardado en 'file.txt':\n\n";

	while(text != '\\')
	{
		input.get(text);
		cout << text;
	}

	cout << "\n\n";
	system("pause");
}

//========================================================
//
//	Inicializar Pantalla

void set_scrn()
{
	system("cls");
	cout << "\n";
}

//========================================================
//
//	WELCOME !!!

void welcome()
{
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