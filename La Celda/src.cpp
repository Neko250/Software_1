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
		cout << "\nInspeccionando la habitacion, encuentras bajo la mesita una moneda,\n"
			 << "tras la cama hay un conducto de ventilacion. Pero esta atornillado a la\n"
			 << "pared... Un momento! La moneda parece encajar perfectamente en los\n"
			 << "tornillos. Sacas los 4 tornillos y ahora, ante ti, hay un posible camino\n"
			 << "a la libertad.\n\n"
			 << "Entras por el conducto. Es muy estrecho y huele a podrido.\n"
			 << "Despues de un rato arrastrandote, llegas a una bifurcacion.\n"
			 << "Un camino sigue hacia un lado, mientras otro baja directamente en vertical.\n\n"
			 << "Bajas por el conducto vertical => 0\n"
			 << "Sigues por el conducto del lateral => 1\n\n"
			 << "===> ";
		cin >> ans;
		
		if(ans)
		{
			cout << "\nPor el conducto lateral, empiezas a notar humedad. cada vez huele mas a \n"
				 << "humedo. Derrepente, el conducto se desprende y caes a una poza llena de\n"
				 << "un agua con un tono verdoso. Desconoces la profundidad de la poza,\n"
				 << "pues no llegas a tocar el fondo.\n\n"
				 << "Buceas para comprobar que es la poza => 0\n"
				 << "Sales a la orilla de la poza => 1\n\n"
				 << "===> ";
			cin >> ans;
			
			if(ans)
			{
				cout << "";
			}
			else
			{
				
			}
		}
		else
		{
			cout << "\n";
		}
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
					 << "Llegas a lo que parece una habitacion de un palacio, pero todo esta\n"
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
						cout << "\nEl salto ha sido fatal. Te encuentras en el suelo del bosque, iluminado por la luz de\n"
							 << "la luna. El frio bosque se extiende ante tus ojos y tu, yaces sobre una fina alfombra de\n"
							 << "agujas de pino secas. Te has roto la pierna que tenias herida. Esta sangrando bastante.\n"
							 << "Tras un rato en el frio bosque el olor de tu sangre atrae una bestia de dimensiones\n"
							 << "colosales. Se aproxima a ti. Tu ingenuo intentas hacerte el muerto. La bestia esta a un\n"
							 << "palmo de ti ahora.\n\n"
							 << "GAME OVER\n\n";
						system("pause");
						return 0;
					}
					else
					{
						cout << "\nAl pasar por la cornisa, esta se desprende y caes al vacio, pero, para suerte tuya, caes\n"
							 << "sobre un monton de paja que habia abajo. Ahora estas fuera de tu prision. Desde ahi fuera\n"
							 << "puedes ver como se extiende hacia el cielo una enorme mansion iluminada por la mistica luz\n"
							 << "de la luna. En una colina cercana se ven luces que parecen ser un poblado.\n\n"
							 << "FIN\n\n";
						system("pause");
						return 0;
					}
				}
				else
				{
					cout << "\nOh no! Una horrible criatura aparece ante tus ojos. Parece que el\n"
						 << "sonido del piano la ha atraido hasta la habitacion en la que estas.\n"
						 << "Tiene la mandibula desencajada y el cuerpo lleno de clavos. Las cuencas\n"
						 << "de sus ojos estan vacias y negras como la oscuridad que envuelve el ambiente.\n"
						 << "La criatura te ha atrapado\n\n"
						 << "GAME OVER\n\n";
					system("pause");
					return 0;
				}
			}
			else
			{
				cout << "\nGolpeas el cerrojo de la trampilla con el candil. El cerrojo ha cedido, pero\n"
					 << "el candil se ha roto en mil pedazos. Ahora estas completamente a oscuras, solo.\n"
					 << "Oyes unos pasos acercarse. No ves absolutamente nada. DIOS! QUE ALGUIEN ME AYUDE!\n"
					 << "Estas desesperado, aquellos pasos, cada vez mas cercanos te estan volviendo loco.\n"
					 << "Que Dios se apiade de mi alma.\n\n"
					 << "GAME OVER\n\n";
				system("pause");
				return 0;
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
			cin >> ans;
			
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
				 << "Echas un vistazo alrededor pero, el camino por el que has venido se ha\n"
				 << "sellado! Ahora no hay marcha atras\n\n"
				 << "Abres la gran puerta acolchada => 0\n"
				 << "Gritas pidiendo auxilio => 1\n\n"
				 << "===> ";
			cin >> ans;
			
			if(ans)
			{
				cout << "\nTus gritos de desesperacion son cada vez mas y mas amargos. Nadie te oye. Ahora\n"
					 << "estas tirado en el suelo, agotado y sin fuerzas. Te desmayas\n\n"
					 << "Te despiertas amarrado a una mesa de torturas. En tu espalda notas las astillas de\n"
					 << "la mesa de madera estropeada. Ante ti aparece un hombre enfermizo, con una robusta\n"
					 << "joroba. En la mano tiene una sierra oxidada con los dientes desgastados por el uso.\n\n"
					 << "GAME OVER\n\n";
				system("pause");
				return 0;
			}
			else
			{
				cout << "\nConsigues abrir a duras penas la puerta. Entras sigilosamente. DIOS! Que es esto?\n"
					 << "Ante tus ojos se extiende un festival de sangre y cadaveres humanos descuartizados.\n"
					 << "La vision de aquella instancia es horrible. Parece la sala de juegos de algun psicotico.\n"
					 << "En una mesa por alli hay muchos papeles, parecen informes de alguna macabra investigacion.\n"
					 << "Lees en uno de ellos:\n\n"
					 << "\"Dia uno: Despues del incidente en aquella tumba egipcia, me siento debil. Me cuesta respirar\n"
					 << "y no consigo conciliar el sueño.\"\n"
					 << "\"Dia 13: La sombra me persigue. La unica forma de mantenerla alejada es ofrecerle dolor\n"
					 << "humano, por lo que tengo que matar para sobrevivir.\"\n\n"
					 << "Que diablos pasa aqui? Sigues buscando. Sin esperarlo, empiezan a pegar golpes en la puerta.\n"
					 << "Cada vez son mas intensos y la puerta empieza a ceder. En la oscuridad de una esquina,\n"
					 << "se oye una voz: \"Ayudame!\" Es un hombre con vida, atado a una mesa. A su lado, una sierra\n"
					 << "oxidada y con los dientes desgastados por el uso. Los golpes no cesan\n\n"
					 << "Coges la sierra y matas al hombre => 0\n"
					 << "Decides no matar al hombre y enfrentarte a la sombra => 1\n\n"
					 << "===> ";
				cin >> ans;
				
				if(ans)
				{
					cout << "\nLa sombra ha conseguido entrar a la sala. Te encuentras ante ella con la sierra en la mano.\n"
						 << "Intentas herir a aquel ser pero se desmaterializa y es inmune al daño fisico.\n\n"
						 << "GAME OVER\n\n";
					system("pause");
					return 0;
				}
				else
				{
					cout << "\nAgarras la sierra firmemente y empiezas a cortar la carne infecta del hombre. Te cambia la\n"
						 << "cara, crees que te has vuelto loco del todo. Despues de un rato creando un circo de visceras\n"
						 << "y gritos, te das cuenta: Eres un asesino. Tras la puerta se escucha la respiracion\n"
						 << "de la sombra sobre la que leiste en aquel diario.\n\n"
						 << "Abres la puerta e intentas escapar => 0\n"
						 << "Decides quedarte en aquella habitacion => 1\n\n"
						 << "===> ";
					cin >> ans;
					
					if(ans)
					{
						cout << "\nAsustado por la sombra has de vivir en aquella estancia, generando dolor a otros para poder\n"
							 << "sobrevivir. Aquel infierno parece que no acabara nunca.\n\n"
							 << "FIN\n\n";
						system("pause");
						return 0;
					}
					else
					{
						cout << "\nAbres la puerta. La sombra estaba alli, ante ti se erguia con un cuerpo mutilado sediento\n"
							 << "de sangre.\n\n"
							 << "GAME OVER\n\n";
						system("pause");
						return 0;
					}
				}
			}
		}
	}
	
	
	return 0;
}