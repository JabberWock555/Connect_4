#include<iostream>
#include "Setup.cpp"
using namespace std;

GameManager::GameManager(){

    char **Board = new char*[rows];
    for (int i = 0; i < rows; i++){
        Board[i] = new char[cols];
    }
}

void GameManager:: Instructions(){};

bool GameManager::isP1turn(){
    return p1Turn;
}

void GameManager::displayBoard(){

    cout<<" "; 
    for(int k = 0; k < cols; k++){
        cout<<" ("<<k+1<<")";
    }
    cout<<endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout<<" | ";
            cout<<Board[i][j];
        }
        cout<<" | "<<endl;
    }
    
    
}

void GameManager:: changeTurn(){
    if(isP1turn){
        p1Turn = false;
    }else{
        p1Turn = true;
    }
}
