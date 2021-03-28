// Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
// Input Format :
// 9 Lines where ith line contains ith row elements separated by space
// Output Format :
//  true or false
// Sample Input :
// 9 0 0 0 2 0 7 5 0 
// 6 0 0 0 5 0 0 4 0 
// 0 2 0 4 0 0 0 1 0 
// 2 0 8 0 0 0 0 0 0 
// 0 7 0 5 0 9 0 6 0 
// 0 0 0 0 0 0 4 0 1 
// 0 1 0 0 0 5 0 8 0 
// 0 9 0 0 7 0 0 0 4 
// 0 8 2 0 4 0 0 0 6
// Sample Output :
// true


#include<bits/stdc++.h>
using namespace std ;

#define N 9

int flag = -1 ;

bool is_row(int sudoku[N][N],int row,int num){
    for(int i = 0 ;i<N;i++){
        if(sudoku[row][i] == num){
            return false;
        }
    }
    return true;
}

bool is_col(int sudoku[N][N],int col,int num){
    for(int i = 0 ;i<N;i++){
        if(sudoku[i][col] == num){
            return false;
        }
    }
    return true;
}

bool is_grid(int sudoku[N][N],int row,int col,int num){

    int row_factor = row - (row % 3);
    int col_factor = col - (col % 3);
    for(int i = 0 ;i<3;i++){
        for(int j = 0 ;j<3;j++){
            if(sudoku[i+row_factor][j+col_factor] == num){
                return false ;
            }
        }
    }
    return true ;
}
bool possible(int sudoku[N][N],int row,int col,int num){

    if(is_row(sudoku,row,num) && is_col(sudoku,col,num) && is_grid(sudoku,row,col,num)){
        return true;
    }

    return false ;

}

bool empty(int sudoku[N][N],int & row,int & col){
    for(int i = 0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            if(sudoku[i][j] == 0){
                row = i;
                col = j;
                return true ;
            }
        }

    }
    return false ;
}


bool sudokuSolver(int sudoku[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
    int row,col;
    if(!empty(sudoku,row,col)){
        return true ;
    }

    for(int i = 1; i<= 9 ; i++){
        if(possible(sudoku,row,col,i)){
            sudoku[row][col] = i;
            if(sudokuSolver(sudoku)){
                return true ;
            }
            sudoku[row][col] = 0 ;

        }
    }
    return false ;


}
