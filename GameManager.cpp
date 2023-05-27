#include<iostream>
#include <vector>
using namespace std;

void printBoard(vector< vector<char> > &board, int m ,int n){
    cout<<" "; 
    for(int k = 0; k < n; k++){
        cout<<" ("<<k+1<<")";
    }
    cout<<endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout<<" | ";
            cout<<board[i][j];
        }
        cout<<" | "<<endl;
    }
    
}
int main()
{
    int m = 6, n = 7;
    
    vector < vector<char> > Board( m , vector<char> (n, ' ')); 
    printBoard(Board, m, n);

    return 0;
}