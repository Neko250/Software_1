
// =======================================================
// ||    ===========================================    ||
// ||  =====                                     =====  ||
// || ====              Library Coded              ==== ||
// ||====                    by                     ====||
// || ====                 Neko250                 ==== ||
// ||  =====                                     =====  ||
// ||    ===========================================    ||
// =======================================================

//=====================================================
//
//	Cabeceras

/*
                                                               .---.
                                                              /  .  \
                                                             |\_/|   |
                                                             |   |  /|
  .----------------------------------------------------------------' |
 /  .-.                                                              |
|  /   \       Programa creado por Carlos Aguilar de la Morena       |
| |\_.  |                                                            |
|\|  | /|                          El                                |
| `---' |                                                            |
|       |                    dd / mm / yyyy                          |
|       |                                                           /
|       |----------------------------------------------------------'
\       |
 \     /
  `---'

*/

/*
       ==========================================
       ||                                      ||
       ||          Programa creado por:        ||
       ||      Carlos Aguilar de la Morena     ||
       ||                                      ||
       ||           El dd / mm / yyyy          ||
       ||                                      ||
       ==========================================
*/

//=====================================================
//
//	Includes y Prototipos

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <time.h>
#include <string.h>
using namespace std;

int random(int);
double pow(double, int);
double fact(double);
unsigned digits(unsigned);
unsigned pos_calc(unsigned, unsigned);
bool prime(unsigned);
double sqrt(double);

void triangle(unsigned);
void spaces(unsigned, unsigned);
void draw(unsigned);

void save_text();
void load_text();

void set_scrn();
void welcome();

string int2string(int);
int string2int(string);
void pause();
//void setWindowSize(int, int);
void remove(int, int);
void print(string, int);
void clearBufer();
void setCursor(int, int);
void setCursor(COORD);
void setColor(int);
void hideConsoleCursor();
void showConsoleCursor();

//=====================================================
//
//	Tipos y Constantes

const char block = 219;
const char beep = 7;

enum color
{
	/* 0 */ black,
	/* 1 */ blue,
	/* 2 */ green,
	/* 3 */ aqua,
	/* 4 */ red,
	/* 5 */ purple,
	/* 6 */ gold,
	/* 7 */ light_light_gray,
	/* 8 */ light_gray,
	/* 9 */ light_blue,
	/* 10 */ light_green,
	/* 11 */ light_aqua,
	/* 12 */ light_red,
	/* 13 */ pink,
	/* 14 */ white,
	/* 15 */ gray
};

//=====================================================
//
//	Definicion funciones

#include "neko250.cpp"

//=====================================================
//
//	Virtual Keys

#define VK_Mouse1 1
#define VK_Mouse2 2

#define VK_Num0 96
#define VK_Num1 97
#define VK_Num2 98
#define VK_Num3 99
#define VK_Num4 100
#define VK_Num5 101
#define VK_Num6 102
#define VK_Num7 103
#define VK_Num8 104
#define VK_Num9 105

#define VK_NumProd 106
#define VK_NumPlus 107
#define VK_NumMinus 109
#define VK_NumDiv 111
#define VK_NumDec 110

#define VK_0 48
#define VK_1 49
#define VK_2 50
#define VK_3 51
#define VK_4 52
#define VK_5 53
#define VK_6 54
#define VK_7 55
#define VK_8 56
#define VK_9 57

#define VK_A 65
#define VK_B 66
#define VK_C 67
#define VK_D 68
#define VK_E 69
#define VK_F 70
#define VK_G 71
#define VK_H 72
#define VK_I 73
#define VK_J 74
#define VK_K 75
#define VK_L 76
#define VK_M 77
#define VK_N 78
#define VK_O 79
#define VK_P 80
#define VK_Q 81
#define VK_R 82
#define VK_S 83
#define VK_T 84
#define VK_U 85
#define VK_V 86
#define VK_W 87
#define VK_X 88
#define VK_Y 89
#define VK_Z 90

#define VK_Egne 192
#define VK_Cedilla 191
#define VK_Plus 187

// No funcionan correctamente en la consola de Windows
//
//#define VK_F1 112
//#define VK_F2 113
//#define VK_F3 114
//#define VK_F4 115
//#define VK_F5 116
//#define VK_F6 117
//#define VK_F7 118
//#define VK_F8 119
//#define VK_F9 120
//#define VK_F11 122
//#define VK_F12 123

#define VK_LCtrl 162
#define VK_RCtrl 163
#define VK_LShift 160
#define VK_RShift 161
#define VK_Alt 164
#define VK_AltGr 165
#define VK_Space 32
#define VK_BloqMayus 20
#define VK_BloqNum 144
#define VK_Windows 91
#define VK_Tab 9
#define VK_App 93
#define VK_Return 13
#define VK_Backspace 8
#define VK_Supr 46
#define VK_Esc 27
#define VK_Insert 45
#define VK_Start 36
#define VK_End 35
#define VK_PrevPag 33
#define VK_NextPag 34

#define VK_Up 38
#define VK_Left 37
#define VK_Down 40
#define VK_Right 39

#define VK_Dot 190
#define VK_Comma 188
#define VK_Line 189
