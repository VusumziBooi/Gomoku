//let 0 denote an empty space, 1 denote black and 2 denote white
//A Player specifies the position in the grid as row,col...both rows and columns starts from 0 and the last entry is 14 in a 15 * 15 board
#include <vector>
#include<iostream>
#include <fstream>
#include "gomoku.h"

using namespace std;

int main(){

    vector<int>sizes;

    ifstream file("input.txt");
    string curr;
    int current;

    while(getline(file, curr)){
        current = stoi(curr);
        sizes.push_back(current);
    }

    for(int i = 0 ; i < sizes.size() ; i++){
        Gomoku gomoku(1,sizes[i]);
        ofs << "size = "<<sizes[i]<<endl;
        srand(time(0));
        while(!gomoku.status){
            int row = (rand() % 10);
            int col = (rand() % 10);
            while(gomoku.board[row][col] != 0){
                row = (rand() % 10);
                col = (rand() % 10);
            }
            gomoku.makeMove(row, col);
        }       
        
    }
    

    return 0;
}
