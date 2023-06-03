#include<iostream>

using namespace std;

enum coin{
    Empty,
    Red, 
    Blue
};


class Coin{

    coin Token;

    public:

    Coin(){

    Token = Empty;

}

coin GetToken()
{
    return Token;
}

void SetToken(coin token_){

    Token = token_;

}

};
