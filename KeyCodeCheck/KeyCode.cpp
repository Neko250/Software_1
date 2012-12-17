#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

void welcome();
void getKey(bool&);

int main()
{
	bool close = false;
	
	welcome();
	
	while(!close)
	{
		getKey(close);
	}
	
	cout << "\n\t";
	system("pause");
	return 0;
}

void welcome()
{
	//	system("mode con: lines=25 cols=80");
	
	cout << "\n"
		 << "\t _____ _     _           _    _____\n"
		 << "\t|  |  |_|___| |_ _ _ ___| |  |  |  |___ _ _ ___\n"
		 << "\t|  |  | |  _|  _| | | .'| |  |    -| -_| | |_ -|\n"
		 << "\t \\___/|_|_| |_| |___|__,|_|  |__|__|___|_  |___|\n"
		 << "\t                                       |___|\n"
		 << "\t         'Esc' to exit\n\n\n";
}

//------------------------------

void getKey(bool& close)
{
	bool run = true;
	
	while(run)
	{
		if(GetAsyncKeyState(0x1B))
		{
			run = false;
			close = true;
		}
		
		for(int i = 0; i < 200; i++)
		{
			if(GetAsyncKeyState(i))
			{
				cout << "\tKey Code: " << i << endl;
			}
		}
		
		Sleep(250);
	}
}