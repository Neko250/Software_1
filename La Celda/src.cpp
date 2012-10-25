/*
       ==========================================
       ||                                      ||
       ||            Source coded by:          ||
       ||      Carlos Aguilar de la Morena     ||
       ||                                      ||
       ||           At  22 / 10 / 2012         ||
       ||                                      ||
       ==========================================
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	bool ans;
	
	cout << "\n\tLa Celda\n"
		 << "========================\n\n"
		 << "Te despiertas en una habitacion. Todo esta sucio y estropeado.\n"
		 << "A tu alrededor tan solo hay una mesita con un candil, que aporta\n"
		 << "una tenue luz a la instancia; una cama con un colchon estropeado\n"
		 << "y una puerta de hierro oxidado. Tras la puerta se escuchan unos\n"
		 << "ruidos realmente molestos, como un lamento continuo y rasgado.\n\n"
		 << "Te desesperas y golpeas la puerta => 0\n"
		 << "Inspeccionas la habitacion a fondo => 1\n\n"
		 << "===> ";
	cin >> ans;
	
	if(ans)
	{
		cout << "\n"
	}
	else
	{
		cout << "\nOyes pasos acercarse. Cada vez son mas intensos y van acompañados\n"
			 << "de unos golpes sordos. Derrepente, la puerta se abre. Te escondes tras\n"
			 << "la cama, cuando el ruido se desvanece decides asomarte a contemplar el\n"
			 << "exterior. Solo hay un largo pasillo, pero todo esta oscuro. Te haces\n"
			 << "con el candil y decides salir de ese antro.\n\n"
			 << "Vas hacia la izquierda => 0\n"
			 << "Vas hacia la derecha => 1\n\n"
			 << "===> ";
		cin >> ans;
		
		if(ans)
		{
			cout << "\nTe adentras en la oscuridad del pasillo, acompanado del candil,\n"
				 << "y andas y andas durante un largo rato... Aquello parece no acabar nunca.\n"
				 << "Llevas una rato andando cuando derrepente encuentras una trampilla\n"
				 << "en el techo, a un lado del pasillo. Esta hecha de madera de roble\n"
				 << "y parece que tiene un cerrojo muy desgastado por los años.\n\n"
				 << "Intentas golpear el cerrojo con el candil a ver si se abre => 0\n"
				 << "Sigues adelante => 1\n\n"
				 << "===> ";
			cin >> ans;
			
			if(ans)
			{
				cout << "\nDejas atras tu miedo y sigues andando por aquel oscuro y humedo pasillo.\n"
					 << "Llegas a lo que parece una habitacion de un palacio, pero todo esta\,"
					 << "destrozado: muebles, lamparas, las paredes... Todo esta en condiciones\n"
					 << "lamentables. Todo a excepcion de un piano de cola que hay en medio\n"
					 << "de la estancia. Te acercas a examinarlo. Pero te quedas paralizado\n"
					 << "cuando empieza a sonar solo, entonando una pieza clasica que resuena\n"
					 << "por toda la habitacion.\n\n"
					 << "Vuelves rapidamente al pasillo => 0\n"
					 << "Arrojas el candil al piano para que arda => 1\n\n"
					 << "===> ";
				cin >> ans;
				
				if(ans)
				{
					cout << "\nLa habitacion se envuelve en llamas, pero ves un balcon en una de las paredes.\n"
						 << "Sales fuera para no morir asfixiado por el humo de aquel crematorio.\n"
						 << "La luz de la luna ilumina un extenso bosque de pinos. A tu lado hay una repisa\n"
						 << "por la que podrias pasar a otro balcon contiguo.\n\n"
						 << "Pasas por la repisa al otro balcon => 0\n"
						 << "Te lanzas al vacia e intentas agarrarte al pino mas cercano => 1\n\n"
						 << "===> ";
					cin >> ans;
					
					if(ans)
					{
						
					}
					else
					{
						
					}
				}
				else
				{
					cout << "\nOh no! Una horrible criatura aparece ante tus ojos. Parece que el\n"
						 << "sonido del piano la ha atraido hasta la habitacion en la que estas.\n"
						 << "Tiene la mandibula desencajada y el cuerpo lleno de clavos. Las cuencas\n"
						 << "de sus ojos estan vacias y negras como la oscuridad que envuelve el ambiente.\n"
						 << "La criatura te ha atrapado\n\n"
						 << "GAME OVER\n\n"
					system("pause");
					return 0;
				}
			}
			else
			{
				
			}
		}
		else
		{
			cout << "\nTe adentras en la oscuridad del pasillo, acompanado del candil,\n"
				 << "encuentras una esquina y al doblarla ves unas escaleras que bajan,\n"
				 << "al fondo de estas se ve una debil luz. Al lado de las escaleras hay\n"
				 << "una puerta hacia la que entra una corriente de aire, ¿sera una salida?\n\n"
				 << "Bajas por las escaleras => 0\n"
				 << "Intentas abrir la puerta => 1\n\n"
				 << "===> ";
			cin >> ans
			
			while(ans)
			{
				cout << "\nLa puerta esta cerrada. Parece que no se abrira.\n\n"
					 << "Bajas por las escaleras => 0\n"
					 << "Intentas abrir la puerta => 1\n\n"
					 << "===> ";
				cin >> ans;
			}
			
			cout << "\nBajando las escaleras, se rompe un madero podrido y caes escaleras abajo.\n"
				 << "Te has herido una pierna y te cuesta andar, pero sacas fuerzas y sigues adelante.\n"
				 << "La luz que se veia desde arriba no era mas que un reflejo de tu candil sobre\n"
				 << "un charcho de agua que habia en el suelo.\n"
				 << "Vagando por la oscuridad encuentras una gran puerta acolchada con\n"
				 << "incrustaciones de bronce. Su diseño desentona notoriamente con el resto del\n"
				 << "lugar, no parece que este descuidada como el resto de aquel lugar.\n"
				 << "Echas un vistazo alrededor pero, ¡el camino por el que has venido se ha\n"
				 << "sellado! Ahora no hay marcha atras\n\n"
				 << "Abres la gran puerta acolchada => 0\n"
				 << "Gritas pidiendo auxilio => \n\n"
				 << "===> ";
			cin >> ans;
			
			if(ans)
			{
				
			}
			else
			{
				
			}
		}
	}
	
	
	return 0;
}