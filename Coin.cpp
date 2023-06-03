#include<iostream>
#include "Setup.cpp"
using namespace std;

Coin::Coin(){

    Token = Empty;

}

coin Coin::getToken(){
    return Token;
}

void Coin::setToken(coin Token){

    this->Token = Token;

}