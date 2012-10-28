/*
       ==========================================
       ||                                      ||
       ||          Programa creado por:        ||
       ||      Carlos Aguilar de la Morena     ||
       ||                                      ||
       ||           El  28 / 10 / 2012         ||
       ||                                      ||
       ==========================================
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int player1HP(10), player2HP(10), player1ATK(2), player2ATK(2),
		potionSTR(3), potionNUM1(3), potionNUM2(3), turn(1);
	char player1Attack, player2Attack;

    //Combat
    while (player1HP > 0 && player2HP > 0)
    {
        system("cls");
        cout << "Player 1's HP = " << player1HP << endl;
        cout << "Player 2's HP = " << player2HP << endl;

        //Player 1's Turn
        if(turn == 1)
        {
           cout << "\nPlayer 1's Turn.\n" << potionNUM1 << " potions left." << "\n1 = Attack, 2 = Potion, 3 = Skip\n\n===>";
           cin >> player1Attack;
		   
           //Player 1 Attacks
           if(player1Attack == '1')
           {
               player2HP = player2HP - player1ATK;
			   
               if(player2HP <= 0)
                {
                    player2HP = 0;
                }
				
               turn = 2;
           }
           //Player 1 Uses Potion
           else if (player1Attack == '2')
           {
               player1HP = player1HP + potionSTR;
               potionNUM1--;
			   
               if (player1HP > 10)
               {
                   player1HP = 10;
               }
			   
               turn = 2;
           }
           //Player 1 Skips
           else
           {
               turn = 2;
           }
        }
		//Player 2's Turn
        else
        {
           cout << "\nPlayer 2's Turn.\n" << potionNUM2 << " potions left." << "\n1 = Attack, 2 = Potion, 3 = Skip\n\n===>";
           cin >> player2Attack;
		   
           //Player 2 Attacks
           if(player2Attack == '1')
           {
               player1HP = player1HP - player2ATK;
			   
               if(player1HP  <= 0)
                {
                    player1HP = 0;
                }
				
               turn = 1;
           }
           //PLayer 2 Uses Potion
           else if (player2Attack == '2')
           {
               player2HP = player2HP + potionSTR;
               potionNUM2--;
			   
               if (player2HP > 10)
               {
                   player2HP = 10;
               }
			   
               turn = 1;
           }
           //Player 2 Skips
           else
           {
               turn = 1;
           }
        }
    }

    // Game Over - Either Player 1 wins or Player 2 Wins.
    //Player 2 Wins
    if(player1HP == 0)
    {
        system("cls");
        cout << "Player 1's HP = " << player1HP << endl;
        cout << "Player 2's HP = " << player2HP << endl;
        cout << "Player 2 Wins!" << endl;
    }
    //Player 1 Wins
    else
    {
        system("cls");
        cout << "Player 1's HP = " << player1HP << endl;
        cout << "Player 2's HP = " << player2HP << endl;
        cout << "Player 1 Wins!" << endl;
    }
	
	system("pause");
    return 0;
}