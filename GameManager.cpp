#include<iostream>
#include "Coin.cpp"
using namespace std;
#define MaxRows 6
#define MaxCols  7
#define MaxWin  5

enum GameStatus{
Playing, 
Draw, 
Red_Win, 
Blue_Win
};

class GameManager{

    private:
    
    int *counter;
    Coin **Board;
    bool p1Turn;
    GameStatus gameStatus;

    bool horizontalCheck(int row_, coin Token){
        int count = 1;
        for(int i = 0; i <  MaxCols; i++){
            if(Token == Board[row_][i].GetToken()){
                count++;
                if (count == MaxWin){
                    return true;
                }
            }else{
                count = 1;
            }
        }
        return false;
    }
    
    bool verticalCheck( int col_, coin Token){
        int count = 1;
        for(int j = 0; j <  MaxRows; j++){
            if(Token == Board[j][col_].GetToken()){
                count++;
                if (count == MaxWin){
                    return true;
                }
            }else{
                count = 1;
            }
        }
        return false;

    }
    
    bool drawCheck(){
        int count = 0;
        for(int i = 0; i < MaxCols; i++){
            count += counter[i];
        }

        if (count >= (MaxCols * MaxRows) -1) return true;

        else return false;
    }
    
    bool diagonalCheck(int row_, int col_, coin Token){
        
        int count = 1;

        //1st Qaud
        for(int i = row_, j = col_; i<MaxRows && j< MaxCols; i++, j++){
            if(Token == Board[i][j].GetToken()){
                count++;
                if (count == MaxWin){
                    return true;
                }
            }else{
                count = 1;
            }
        }

        //2nd Quad
        for(int i = row_, j = col_; i >= 0 && j< MaxCols; i--, j++){
            if(Token == Board[i][j].GetToken()){
                count++;
                if (count == MaxWin){
                    return true;
                }
            }else{
                count = 1;
            }
        }

        //3rd Quad
        for(int i = row_, j = col_; i >= 0 && j >= 0; i--, j--){
            if(Token == Board[i][j].GetToken()){
                count++;
                if (count == MaxWin){
                    return true;
                }
            }else{
                count = 1;
            }
        }

        //4th Quad
        for(int i = row_, j = col_; i<MaxRows && j >= 0; i++, j--){
            if(Token == Board[i][j].GetToken()){
                count++;
                if (count == MaxWin){
                    return true;
                }
            }else{
                count = 1;
            }
        }

        if(count == MaxWin) return true;

        else return false;
    }

    GameStatus checkWin(int row_, int col_, coin Token, bool p1){

       if(horizontalCheck(row_, Token) || verticalCheck(col_, Token) || diagonalCheck(row_, col_, Token) ){

           if(p1) return Red_Win;

           else return Blue_Win;

       }else if(drawCheck()){
           return Draw;
       }
       else return Playing;


    }


    public:
    
    GameManager(){
    
        counter = new int[MaxCols];
    
        Board = new Coin*[MaxCols];
        for (int i = 0; i < MaxCols;i++ ){
            Board[i] = new Coin[MaxRows];
        }
    
        p1Turn = true;
    
        gameStatus = Playing;
    }
    
    void Intro(){

        cout<<"\n\n\n           Welcome to CONNECT-4 Game! \nGet ready to challenge your strategic skills as you compete against a friend in this classic board game.\nIn Connect-4, your objective is to be the first player to align four of your colored coins in a row, either vertically, horizontally, or diagonally on the game board."<<endl;

        cout<<endl<<"\nInstructions:\n"<<endl;
        cout<<"1.   The game is played by two players, taking turns to place their colored coins on the game board.      \nOne player will have red coins, and the other will have blue coins."<<endl;
        cout<<"2.   To make a move, each player will enter the column number where they want to drop their coin.      \nThe column number ranges from 1 to 7, representing the seven columns on the game board. Each column can hold a maximum of six coins."<<endl;
        cout<<"3.   The game board will be displayed as a grid of 6 rows and 7 columns. The rows are numbered from 1 to 6, starting from the bottom.     \n The columns are numbered from 1 to 7, starting from the left."<<endl;
        cout<<"4.   Players will take turns placing their coins on the board. The first player will place a red coin, followed by the second player who will place a blue coin.      \nThe coins will drop to the lowest available position in the selected column."<<endl;
        cout<<"5.   The game will continue until one player successfully aligns four of their colored coins either vertically, horizontally, or diagonally.      \nIf all positions on the board are filled and no player has achieved four in a row, the game will be declared a draw."<<endl;
        cout<<"6.   After each move, the updated game board will be displayed. The red coins will be represented by 'R', and the blue coins will be represented by 'B'.     \nEmpty positions on the board will be represented by spaces (' ')."<<endl;
        cout<<"7.   When it is your turn, simply enter the column number where you want to drop your coin.      \nMake sure to input a valid column number that is not already filled."<<endl;
        cout<<"8.   The first player to successfully align four coins in a row will be declared the winner.      \nIf the game ends in a draw, both players will be considered tied."<<endl;
        
        cout<<"\nNow that you understand the rules, grab a friend and enjoy the Connect-4 Game! May the best strategist win! "<<endl<<endl;
        
        displayBoard();
}
    
    bool isP1turn()
    {
        return p1Turn;
    }
    
    void displayBoard(){
    
        cout<<" "; 
        for(int k = 0; k < MaxCols; k++){
            cout<<" ("<<k+1<<")";
        }
        cout<<endl;
        for(int i = 0; i < MaxRows; i++){
            for(int j = 0; j < MaxCols; j++){
                cout<<" | ";
                
                switch (Board[i][j].GetToken())
                {
                case Empty:
                cout<<" ";
                    break;
                case Red:
                cout<<"R";
                    break;
                case Blue:
                cout<<"B";
                    break;
                }
            }
            cout<<" | "<<endl<<endl;
        }
    }
    
    void changeTurn(){
      p1Turn = !p1Turn;
  }
    
    GameStatus getGameStatus(){
      return gameStatus;
  }
    
    void setGameStatus(GameStatus status){
      gameStatus = status;
  }
    
    bool insertCoin(int col_, bool isPlayer1){

    coin tempToken;

    int row_ = (MaxRows -1 )- counter[col_];

    isPlayer1 ? tempToken = Red : tempToken = Blue;

    if (counter[col_] == MaxRows){
        cout<<" The Column is Full!\n"<<endl;
        return false;
    }
    if (Board[row_][col_].GetToken() == Empty){

        Board[row_][col_].SetToken(tempToken);

    }
    counter[col_]++;

    if(gameStatus != Playing) return false;

    setGameStatus(checkWin(row_, col_, tempToken, isPlayer1));

    return true;
}
    
  
    ~GameManager(){

        delete[] counter;

        for (int i = 0; i < MaxCols;i++ ){
            delete [] Board[i];
        }
        delete [] Board;
    }
    
};


