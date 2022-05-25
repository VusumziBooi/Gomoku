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

    Gomoku(int player){
        this->player = player;
        
    }
    
    bool isWinner(int player){
        if(horizontal_check(player) == true){
            return true;
        }
        if(vertical_check(player) == true){
            return true;
        }
        if(upper_diagonal_check(player) == true){
            return true;
        }
        if(lower_diagonal_check(player) == true){
            return true;
        }
        return false;
    }

    bool vertical_check(int player){
        for(int col = 0; col < n; col++){
            for(int row = 0;row < n; row++){
                int assessed_index = col;       //This is the col index of current point on board
                int first_index_right = col + 1;        // col index of first element to the right of current point
                int second_index_right = col + 2;       // col index of second element to the right of current point
                int third_index_right = col + 3;        // col index of third element to the right of current point

                int first_index_left = col - 1;        // col index of first element to the left of current point
                int second_index_left = col - 2;       // col index of second element to the left of current point
                int third_index_left = col - 3;        // col index of third element to the left of current point

                
                if((first_index_right>= 0 & first_index_right<n)&&
                (second_index_right>= 0 & second_index_right<n)&&
                    (third_index_right>= 0 & third_index_right<n)){
                        

                    if((board[assessed_index][row] == player)&&
                    (board[first_index_right][row] == player)&&
                    (board[second_index_right][row] == player)&&
                    (board[third_index_right][row] == player)){

                        return true;
                    }
                    else if ((board[assessed_index][row] == player)&&
                    (board[first_index_left][row] == player)&&
                    (board[second_index_left][row] == player)&&
                    (board[third_index_left][row] == player))
                    {
                        return true;
                    }
                    
                }

                
            }
        }
        return false;
    }

    bool horizontal_check(int player){
        for(int col = 0; col < n; col++){
            for(int row = 0;row < n; row++){
                int assessed_index = row;       //This is the col index of current point on board
                int first_index_right = row + 1;        // col index of first element to the below of current point
                int second_index_right = row + 2;       // col index of second element to the below of current point
                int third_index_right = row + 3;        // col index of third element to the below of current point

                int first_index_left = row - 1;        // col index of first element to the above of current point
                int second_index_left = row - 2;       // col index of second element to the above of current point
                int third_index_left = row - 3;        // col index of third element to the above of current point

                
                if((first_index_right>= 0 & first_index_right<n)&&
                (second_index_right>= 0 & second_index_right<n)&&
                    (third_index_right>= 0 & third_index_right<n)){
                        

                    if((board[col][assessed_index] == player)&&
                    (board[col][first_index_right] == player)&&
                    (board[col][second_index_right] == player)&&
                    (board[col][third_index_right] == player)){
                        
                        return true;
                    }
                    else if ((board[col][assessed_index] == player)&&
                    (board[col][first_index_left] == player)&&
                    (board[col][second_index_left] == player)&&
                    (board[col][third_index_left] == player))
                    {
                        return true;
                    }
                    
                }

                
            }
        }
        return false;
    }
    
    bool upper_diagonal_check(int player){
        for(int col = 0; col < n; col++){
            for(int row = 0;row < n; row++){
                int assessed_index_row = row;       //This is the row index of current point on board
                int assessed_index_col = col;       //This is the col index of current point on board
                int first_index_ud_right_row = row - 1;        // row index of first element in right upper diagonal of current point
                int first_index_ud_right_col = col + 1;        // col index of first element in right upper diagonal of current point
                int second_index_ud_right_row = row - 2;       // row index of second element in right upper diagonal current point
                int second_index_ud_right_col = col + 2;       // col index of second element in right upper diagonal current point
                int third_index_ud_right_row = row - 3;        // row index of third element in right upper diagonal current point
                int third_index_ud_right_col = col + 3;        // col index of third element in right upper diagonal current point


                int first_index_ud_left_row = row - 1;        // row index of first element in left upper diagonal of current point
                int first_index_ud_left_col = col- 1;         // col index of third element in left upper diagonal of current point
                int second_index_ud_left_row = row - 2;       // row index of second element in left upper diagonal of current point
                int second_index_ud_left_col = col - 2;       // col index of second element in left upper diagonal of current point
                int third_index_ud_left_row = row - 3;        // row index of third element in left upper diagonal of current point
                int third_index_ud_left_col = col - 3;        // col index of third element in left upper diagonal of current point
                
                if((first_index_ud_right_col>= 0 & first_index_ud_right_col<n & first_index_ud_right_row>= 0 & first_index_ud_right_row<n)&&
                (first_index_ud_left_col>= 0 & first_index_ud_left_col<n & first_index_ud_left_row>= 0 & first_index_ud_left_row<n)&&
                (second_index_ud_right_col>= 0 & second_index_ud_right_col<n & second_index_ud_right_row>= 0 & second_index_ud_right_row<n)&&
                (second_index_ud_left_col>= 0 & second_index_ud_left_col<n & second_index_ud_left_row>= 0 & second_index_ud_left_row<n)&&
                (third_index_ud_right_col>= 0 & third_index_ud_right_col<n & third_index_ud_right_row>= 0 & third_index_ud_right_row<n)&&
                (third_index_ud_left_col>= 0 & third_index_ud_left_col<n & third_index_ud_left_row>= 0 & third_index_ud_left_row<n)){
                    

                    if((board[assessed_index_row][assessed_index_col] == player)&&
                    (board[first_index_ud_right_row][first_index_ud_right_col] == player)&&
                    (board[second_index_ud_right_row][second_index_ud_right_col] == player)&&
                    (board[third_index_ud_right_row][third_index_ud_right_col] == player)){
                        
                        return true;
                    }
                    else if ((board[assessed_index_row][assessed_index_col] == player)&&
                    (board[first_index_ud_left_row][first_index_ud_left_col] == player)&&
                    (board[second_index_ud_left_row][second_index_ud_left_col] == player)&&
                    (board[third_index_ud_left_row][third_index_ud_left_col] == player))
                    {
                        return true;
                    }
                    
                }
            }
        }
        return false;
    }

    bool lower_diagonal_check(int player){
        for(int col = 0; col < n; col++){
            for(int row = 0;row < n; row++){
                int assessed_index_row = row;       //This is the row index of current point on board
                int assessed_index_col = col;       //This is the col index of current point on board
                int first_index_ld_right_row = row + 1;        // row index of first in right lower diagonal of current point
                int first_index_ld_right_col = col + 1;        // col index of first in right lower diagonal of current point
                int second_index_ld_right_row = row + 2;       // row index of second in right lower diagonal of current point
                int second_index_ld_right_col = col + 2;       // col index of second in right lower diagonal of current point
                int third_index_ld_right_row = row + 3;        // row index of third in right lower diagonal of current point
                int third_index_ld_right_col = col + 3;        // col index of third in right lower diagonal of current point


                int first_index_ld_left_row = row + 1;        // row index of first element in left lower diagonal of current point
                int first_index_ld_left_col = col- 1;         // col index of first element in left lower diagonal of current point
                int second_index_ld_left_row = row + 2;       // row index of second element in left lower diagonal of current point
                int second_index_ld_left_col = col - 2;       // col index of second element in left lower diagonal of current point
                int third_index_ld_left_row = row + 3;        // row index of third element in left lower diagonal of current point
                int third_index_ld_left_col = col - 3;        // col index of third element in left lower diagonal of current point
                
                if((first_index_ld_right_col>= 0 & first_index_ld_right_col<n & first_index_ld_right_row>= 0 & first_index_ld_right_row<n)&&
                (first_index_ld_left_col>= 0 & first_index_ld_left_col<n & first_index_ld_left_row>= 0 & first_index_ld_left_row<n)&&
                (second_index_ld_right_col>= 0 & second_index_ld_right_col<n & second_index_ld_right_row>= 0 & second_index_ld_right_row<n)&&
                (second_index_ld_left_col>= 0 & second_index_ld_left_col<n & second_index_ld_left_row>= 0 & second_index_ld_left_row<n)&&
                (third_index_ld_right_col>= 0 & third_index_ld_right_col<n & third_index_ld_right_row>= 0 & third_index_ld_right_row<n)&&
                (third_index_ld_left_col>= 0 & third_index_ld_left_col<n & third_index_ld_left_row>= 0 & third_index_ld_left_row<n)){
                    

                    if((board[assessed_index_row][assessed_index_col] == player)&&
                    (board[first_index_ld_right_row][first_index_ld_right_col] == player)&&
                    (board[second_index_ld_right_row][second_index_ld_right_col] == player)&&
                    (board[third_index_ld_right_row][third_index_ld_right_col] == player)){
                        
                        return true;
                    }
                    else if ((board[assessed_index_row][assessed_index_col] == player)&&
                    (board[first_index_ld_left_row][first_index_ld_left_col] == player)&&
                    (board[second_index_ld_left_row][second_index_ld_left_col] == player)&&
                    (board[third_index_ld_left_row][third_index_ld_left_col] == player))
                    {
                        
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
        else{
            board[row][col] = 2;
        }

        

        //Check if a player won
        if(isWinner(player)){
            cout << "Game over!!!  player  " << player << " Won \n"<<endl;
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

   

    while(gomoku.isWinner(1) == false && gomoku.isWinner(2) == false){

        int row = (rand() % 10);
        int col = (rand() % 10);


        gomoku.makeMove(row, col);

        gomoku.printBoard();

        gomoku.isWinner(1);
        gomoku.isWinner(2);
    }

    // gomoku.printBoard();
    // gomoku.isWinner(2);
    
    
    return 0;
}



