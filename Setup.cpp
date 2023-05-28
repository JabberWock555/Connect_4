#include<iostream>
using namespace std;

int rows= 6, cols = 7;

enum GameStatus{
Playing, 
Draw, 
Red_Win, 
Blue_Win
};

enum coin{
    Empty,
    Red, 
    Blue
};

class Coin{

    coin Token;

    public:
    Coin();
    coin getToken();
    void setToken(coin Token);

};

class GameManager{

    coin **Board;
    int *counter;
    bool p1Turn;
    GameStatus gameStatus;

    public:
    GameManager();
    void Instructions();
    bool isP1turn();
    void displayBoard();
    void changeTurn();
    GameStatus getGameStatus();
    void setGameStatus(GameStatus);
    
    
};


int main()
{
    
    return 0;
}