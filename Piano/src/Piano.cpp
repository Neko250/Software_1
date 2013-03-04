/*

	Work.cpp

*/

#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

//==============================

#define VK_Esc 0x1B

#define VK_Z 0x5A
#define VK_S 0x53
#define VK_X 0x58
#define VK_D 0x44
#define VK_C 0x43
#define VK_V 0x56
#define VK_G 0x47
#define VK_B 0x42
#define VK_H 0x48
#define VK_N 0x4E
#define VK_J 0x4A
#define VK_M 0x4D

#define VK_Q 0x51
#define VK_2 0x32
#define VK_W 0x57
#define VK_3 0x33
#define VK_E 0x45
#define VK_R 0x52
#define VK_5 0x35
#define VK_T 0x54
#define VK_6 0x36
#define VK_Y 0x59
#define VK_7 0x37
#define VK_U 0x55

//==============================

const int time = 250;

const int C = 262;
const int Db = 277;
const int D = 294;
const int Eb = 311;
const int E = 330;
const int F = 349;
const int Gb = 370;
const int G = 392;
const int Ab = 415;
const int A = 440;
const int Bb = 466;
const int B = 494;

const int C2 = 523;
const int Db2 = 554;
const int D2 = 587;
const int Eb2 = 622;
const int E2 = 659;
const int F2 = 699;
const int Gb2 = 740;
const int G2 = 784;
const int Ab2 = 831;
const int A2 = 880;
const int Bb2 = 932;
const int B2 = 988;

//==============================

void welcome();
void play(bool&);

//==============================

int main()
{
	bool exit = false;
	
	system("mode con: lines=16 cols=74");
	
	welcome();
	
	while(!exit)
	{
		play(exit);
	}
	
	return 0;
}

//==============================

void welcome()
{
	cout << "\n"
		 << "\t       _____ _\n"
		 << "\t      |  _  |_|___ ___ ___\n"
		 << "\t      |   __| | .'|   | . |\n"
		 << "\t      |__|  |_|__,|_|_|___|       'Esc' to exit\n\n"
		 << "\t _______________________________________________________\n"
		 << "\t|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |\n"
		 << "\t|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |\n"
		 << "\t|  |S| |D|  |  |G| |H| |J|  |  |2| |3|  |  |5| |6| |7|  |\n"
		 << "\t|  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |  |_| |_| |_|  |\n"
		 << "\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |\n"
		 << "\t| Z | X | C | V | B | N | M | Q | W | E | R | T | Y | U |\n"
		 << "\t|___|___|___|___|___|___|___|___|___|___|___|___|___|___|";
}

//==============================

void play(bool& exit)
{
	bool run = true;
	
	while(run)
	{
		if(GetAsyncKeyState(VK_Esc))
		{
			run = false;
			exit = true;
		}
		
		//==============================
		
		if(GetAsyncKeyState(VK_Z))
		{
			Beep(C, time);
		}
		
		if(GetAsyncKeyState(VK_S))
		{
			Beep(Db, time);
		}
		
		if(GetAsyncKeyState(VK_X))
		{
			Beep(D, time);
		}
		
		if(GetAsyncKeyState(VK_D))
		{
			Beep(Eb, time);
		}
		
		if(GetAsyncKeyState(VK_C))
		{
			Beep(E, time);
		}
		
		if(GetAsyncKeyState(VK_V))
		{
			Beep(F, time);
		}
		
		if(GetAsyncKeyState(VK_G))
		{
			Beep(Gb, time);
		}
		
		if(GetAsyncKeyState(VK_B))
		{
			Beep(G, time);
		}
		
		if(GetAsyncKeyState(VK_H))
		{
			Beep(Ab, time);
		}
		
		if(GetAsyncKeyState(VK_N))
		{
			Beep(A, time);
		}
		
		if(GetAsyncKeyState(VK_J))
		{
			Beep(Bb, time);
		}
		
		if(GetAsyncKeyState(VK_M))
		{
			Beep(B, time);
		}
		
		//==============================
		
		if(GetAsyncKeyState(VK_Q))
		{
			Beep(C2, time);
		}
		
		if(GetAsyncKeyState(VK_2))
		{
			Beep(Db2, time);
		}
		
		if(GetAsyncKeyState(VK_W))
		{
			Beep(D2, time);
		}
		
		if(GetAsyncKeyState(VK_3))
		{
			Beep(Eb2, time);
		}
		
		if(GetAsyncKeyState(VK_E))
		{
			Beep(E2, time);
		}
		
		if(GetAsyncKeyState(VK_R))
		{
			Beep(F2, time);
		}
		
		if(GetAsyncKeyState(VK_5))
		{
			Beep(Gb2, time);
		}
		
		if(GetAsyncKeyState(VK_T))
		{
			Beep(G2, time);
		}
		
		if(GetAsyncKeyState(VK_6))
		{
			Beep(Ab2, time);
		}
		
		if(GetAsyncKeyState(VK_Y))
		{
			Beep(A2, time);
		}
		
		if(GetAsyncKeyState(VK_7))
		{
			Beep(Bb2, time);
		}
		
		if(GetAsyncKeyState(VK_U))
		{
			Beep(B2, time);
		}
	}
}