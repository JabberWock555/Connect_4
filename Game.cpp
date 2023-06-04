#include<iostream>
#include "GameManager.cpp"
using namespace std;

int main()
{
    GameManager gameManager;
    gameManager.Intro();
    int inputCol = 1;

    while (true)
    {
        do{
            //add text
            if(inputCol < 1 || inputCol > MaxCols){
                cout<<"\nPlease Enter a valid Input number between 1-7:    ";
            }
            else if(gameManager.isP1turn()){
                cout<<"\nPlayer 1 turn (RED):    ";
            }
            else{
                cout<<"\nPlayer 2 turn (BLUE):    ";
            }
            cin >> inputCol ;
            cout<<endl;
        }while(inputCol < 1 || inputCol > MaxCols);

        if(!gameManager.insertCoin(inputCol - 1, gameManager.isP1turn())){

            gameManager.displayBoard();
            continue;
        }
       
        gameManager.displayBoard();

        if(gameManager.getGameStatus() != Playing){
            
            switch (gameManager.getGameStatus()){

                case Red_Win:
                    cout<<"\n\n***  Winner --->  Player 1 (RED)!!!\n"<<endl;
                    break;
                case Blue_Win:
                    cout<<"\n\n***  Winner --->  Player 2 (BLUE)!!\n"<<endl;
                    break;
                case Draw:
                    cout<<"\n\nIts a Draw!\n"<<endl;
                    break;
                default:
                    break;

            }
            
            break;
        }

        gameManager.changeTurn();
    }

    cout<<"\n\nThanks for Playing!\n\n";

    return 0;
}