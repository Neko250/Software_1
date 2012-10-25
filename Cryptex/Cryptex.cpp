/*
       ==========================================
       ||                                      ||
       ||          Programa creado por:        ||
       ||      Carlos Aguilar de la Morena     ||
       ||          Pablo Sabín Cazorla         ||
       ||           El  10 / 10 / 2012         ||
       ||                                      ||
       ==========================================
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
	int salt(0), intentos(3), random(1), i(0);
	char opcion('E'), frase[150];
	string pass("password");

	cout << "\n\tBienvenido\n\n";
	cout << "Introduce el password para comenzar: ";
	cin >> pass;

	while((pass != ("mushroom")) && (pass != ("Longchicken2x1")))
	{
		intentos -= 1;
		if(intentos == 0)
		{
			cout << endl << "Usuario no identificado\n";
			system("pause");
			return 0;
		}
		cout << endl << "Password Incorrecto. Acceso Denegado\n"
			 << "Intentelo de nuevo, le quedan " << intentos << " intentos: ";
		cin >> pass;
	}

	if(pass == "Longchicken2x1")
	{
		cout << endl << "Password Correcto. Acceso Concedido\n"
			 << "\n\tBienvenido, Carlos, a Cryptex\n\n";
	}
	else
	{
		cout << endl << "Password Correcto. Acceso Concedido\n"
			 << "\n\tBienvenido, Pablo, a Cryptex\n\n";
	}

	cout << "Que modo desea usar? ==> ";
	cin >> opcion;
	
	while((opcion != 'E') && (opcion != 'D'))
	{
		cout << "Las opciones disponibles son 'E' (Encriptar) y 'D' (Desencriptar)\n"
			 << "Intentelo de nuevo ==> ";
		cin >> opcion;
	}

	if(opcion == 'E')
	{
		cout << "Introduzca la Sal: ";
		cin >> salt;
		cout << "\nIntroduzca los caracteres:\n\n";

		while(random > 0)
		{
			cin >> frase;
			for(; i < strlen(frase); i++)
			{
				if((int(frase[i]) + salt) > 126)
				{
					frase[i] = ((int(frase[i]) + salt) - 126 + 32);
				}
				else
				{
					frase[i] = (int(frase[i]) + salt);
				}
			}
			cout << "\t" << frase;
			i = 0;
			cout << endl << endl;
		}
	}

	if(opcion == 'D')
	{
		cout << "Introduzca la Sal: ";
		cin >> salt;
		cout << "\nIntroduzca los caracteres:\n\n";

		while(random > 0)
		{
			cin >> frase;
			for(; i < strlen(frase); i++)
			{
				if((int(frase[i]) - salt) < 33)
				{
					frase[i] = ((int(frase[i]) - salt) + 126 - 32);
				}
				else
				{
					frase[i] = (int(frase[i]) - salt);
				}
			}
			cout << "\t" << frase;
			i = 0;
			cout << endl << endl;
		}
	}

	return 0;
}