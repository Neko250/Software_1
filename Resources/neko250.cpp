
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
//	Potencia

double pow(double a, int b)
{
	double ans(1);

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

	position = (N / int(pow(double(10), (i - 1)))) % 10;
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
//	Raiz cuadrada

double sqrt(double x)
{
	double r = x, t = 0;
	
	while(t != r)
	{
		t = r;
		r = (((x / r) + r) / 2);
	}
	
	return r;
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
	cout << "\n\t";
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

//========================================================
//
//	Convierte de entero a string

string int2string(int num) {
	int dig = digits(num) - 1;
	string ans = "";
	ans += char( (num / pow(10, dig)) + 48 );
	num %= int(pow(10, dig));
	dig--;
	
	for( ; dig >= 0; dig--) {
		ans += char( (num / pow(10, dig)) + 48 );
		num %= int(pow(10, dig));
	}
	
	return ans;
}

//========================================================
//
//	Convierte de string a entero

int string2int(string num) {
	int ans = 0;
	
	for(int i = num.size() - 1; i >= 0; i--) {
		ans += int( (num[i] - 48) * pow(10, i) );
	}
	
	return ans;
}

//========================================================
//
//	Pausa el flujo de ejecucion del programa

void pause() {
	system("pause");
}

//========================================================
//
//	Redimensiona la ventana al tamano especificado
/*
void setWindowSize(int width, int height) {
	string message = "mode con: lines=";
	
	message += int2string(height);
	message += " cols=";
	message += int2string(width);
	
	system(message);
}
*/
//========================================================
//
//	Borra 'times' elementos con una pausa de 'step' entre char y char

void remove(int times, int step) {
	for(int i = 0; i < times; i++) {
		cout << bk << sp << bk;
		Sleep(step);
	}
}

//========================================================
//
//	Imprime un texto con pausa de 'step' entre char y char

void print(string text, int step) {
	for(int i = 0; text[i] != '\0'; i++) {
		cout << text[i];
		Sleep(step);
	}
}

//========================================================
//
//	Limpia el bufer de entrada

void clearBufer()
{
	HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
}

//========================================================
//
//	Situa el cursor de la consola en (x, y)

void setCursor(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//========================================================
//
//	Situa el cursor de la consola en 'pos'

void setCursor(COORD pos)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//========================================================
//
//	Añade color al siguiente texto impreso

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//========================================================
//
//	Esconde el cursor de la consola

void hideConsoleCursor()
{
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize = 100;
	ConCurInf.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConCurInf);
}

//========================================================
//
//	Muestra el cursor de la consola

void showConsoleCursor()
{
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize = 100;
	ConCurInf.bVisible = true;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConCurInf);
}

//========================================================
//
//	

