#include<bits/stdc++.h>
using namespace std ;

# define n 9

int flag = -1 ;
bool is_row(int sudoku[n][n],int row,int num){
    for(int i = 0 ;i<n;i++){
        if(sudoku[row][i] == num){
            return false;
        }
    }
    return true;
}
bool is_col(int sudoku[n][n],int col,int num){
    for(int i = 0 ;i<n;i++){
        if(sudoku[i][col] == num){
            return false;
        }
    }
    return true;
}

bool is_grid(int sudoku[n][n],int row,int col,int num){

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
bool possible(int sudoku[n][n],int row,int col,int num){

    if(is_row(sudoku,row,num) && is_col(sudoku,col,num) && is_grid(sudoku,row,col,num)){
        return true;
    }

    return false ;

}

bool empty(int sudoku[n][n],int & row,int & col){
    for(int i = 0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(sudoku[i][j] == 0){
                row = i;
                col = j;
                return true ;
            }
        }

    }
    return false ;
}

bool sudoku_solver(int sudoku[n][n]){
    int row,col;
    if(!empty(sudoku,row,col)){
        return true ;
    }

    for(int i = 1; i<= 9 ; i++){
        if(possible(sudoku,row,col,i)){
            sudoku[row][col] = i;
            if(sudoku_solver(sudoku)){
                return true ;
            }
            sudoku[row][col] = 0 ;

        }
    }
    return false ;
}


void input_sudoku(int sudoku[n][n]){
    for(int i = 0 ;i<n;i++){

        string s;
        cin>> s;

        for(int j = 0; j<s.length() ; j++){
            sudoku[i][j] = s[j] - '0';
        }
    }
}
void output_sudoku(int sudoku[n][n]){
    for(int i = 0 ;i<n;i++){
        for(int j = 0; j<n ; j++){
            cout<<sudoku[i][j];
        }
        cout<<endl;
    }

}
int main(void){
    
    int sudoku[n][n] ;
    input_sudoku(sudoku);
    sudoku_solver(sudoku);
    output_sudoku(sudoku);

}