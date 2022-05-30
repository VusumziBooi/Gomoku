//let 0 denote an empty space, 1 denote black and 2 denote white
//A Player specifies the position in the grid as row,col...both rows and columns starts from 0 and the last entry is 14 in a 15 * 15 board
#include<iostream>
#include<string>
#include <vector>
using namespace std;
//Declare our board
int n = 15;
int board[15][15] = {0};
struct Gomoku{
    int player;
    int previous;
    bool status = false;

    Gomoku(int player){
        this->player = player;
        
    }
    
    bool isWinner(int player){
        if(is_horizontal(player) || is_vertical(player) || is_upper_diagonal(player) || is_lower_diagonal(player))return true;
        return false;
    }

    bool match(int curr,int n1,int n2,int n3,int n4){
        if(curr == n1 && curr == n2 && curr == n3 && curr == n4){
            return true;
        }
        return false;
    }

    bool is_horizontal(int player){
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n - 4 ; col++){
                if(board[row][col] == player){//point of interest
                    int n1 = board[row][col+1];
                    int n2 = board[row][col+2];
                    int n3 = board[row][col+3];
                    int n4 = board[row][col+4];
                    if(match(board[row][col],n1,n2,n3,n4)){
                        return true;
                    }
                }
                else{
                    continue;
                }
            }
        }
        return false;
    }

    bool is_vertical(int player){
        for(int row = 0 ; row < n-4 ; row++){
            for(int col = 0 ; col < n ; col++){
                if(board[row][col] == player){
                    int n1 = board[row+1][col];
                    int n2 = board[row+2][col];
                    int n3 = board[row+3][col];
                    int n4 = board[row+4][col];
                    if(match(board[row][col], n1, n2, n3,n4)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool is_lower_diagonal(int player){
        for(int row = 0 ; row < n - 4 ; row ++){
            for(int col = 0 ; col < n-4 ; col++){
                if(board[row][col] == player){
                    int n1 = board[row+1][col+1];
                    int n2 = board[row+2][col+2];
                    int n3 = board[row+3][col+3];
                    int n4 = board[row+4][col+4];
                    if(match(board[row][col], n1, n2, n3,n4)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool is_upper_diagonal(int player){
        for(int row = 0 ; row < n - 4 ; row++){
            for(int col = 4 ; col < n ; col++){
                if(board[row][col] == player){
                    int n1 = board[row+1][col-1];
                    int n2 = board[row+2][col-2];
                    int n3 = board[row+3][col-3];
                    int n4 = board[row+4][col-4];
                    if(match(board[row][col], n1, n2, n3,n4)){
                        return true;
                    }
                }
            }
        }
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

        cout << endl;
    }

    void makeMove(int row, int col){
        if(player == 1){//place a black piece 
            board[row][col] = 1;
        }
        else{//place a white piece
            board[row][col] = 2;
        }
        //Check if a player won
        if(isWinner(player)){
            cout << "Game over!!!  player  " << player << " Won \n"<<"Final board configuration is "<<endl;
            printBoard();
            status = true;
            return;
        }
        else{
            //Change turns (different player)
            if(player == 1){
                player = 2;
                previous = 1;
            }
            else{
                player = 1;
                previous = 2;
            }
        }

        cout << "After player " << previous << " Board position is: "<<endl;
        printBoard();
        cout <<endl; 
    }

};

int main(){
    
    Gomoku gomoku(2);
    srand(time(0));
    while(!gomoku.status){
        int row = (rand() % 10);
        int col = (rand() % 10);
        while(board[row][col] != 0){
            row = (rand() % 10);
            col = (rand() % 10);
        }
        gomoku.makeMove(row, col);
        
        
    }
    
    
    return 0;
}
