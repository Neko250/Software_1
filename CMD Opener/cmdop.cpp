#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int main()
{
	int x;
	
	system("mode con: lines=3 cols=23");
	system("title CMD Opener");
	
	cout << "\n Number of Windows: ";
	cin >> x;
	
	while(x > 0)
	{
		system("start cmd.exe /k \"C: && cd C:\\Work\"");
		x--;
	}
	
	return 0;
}