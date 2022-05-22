//let 0 denote an empty space, 1 denote black and 2 denote white
//A Player specifies the position in the grid as row,col...both rows and columns starts from 0 and the last entry is 14 in a 15 * 15 board
#include<iostream>
#include<string>
using namespace std;

//Declare our board
int board[15][15] = {0};
int n = 15;
struct Gomoku{
    int player;
    Gomoku(int player){
        this->player = player;
    }

     bool isWinner(int player){
        return false;
     }
    void printBoard(){
        for(int i = 0 ; i < n ; i++){
            string Delimeter = "";
            for(int j = 0 ; j < n ; j++){
                cout << Delimeter << board[i][j];
                Delimeter = " ";
            }
            cout << endl;
        }
    }

    void makeMove(int row, int col){
        if(player == 1){//place a black piece 
            board[row][col] = 1;
        }
        else{
            board[row][col] = 2;
        }

        //Check if a player won
        if(isWinner(player)){
            cout << "Game over!!!  player  " << player << " Won ";
            return;
        }
        else{
            //Change turns (different player)
            if(player == 1){
                player = 2;
            }
            else{
                player = 1;
            }
        } 
    }

};

int main(){
    Gomoku gomoku(2);
    gomoku.printBoard();
    return 0;
}