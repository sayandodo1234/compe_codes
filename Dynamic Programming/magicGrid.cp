// Magic Grid Problem
// Send Feedback
// You are given a magic grid A with R rows and C columns. In the cells of the grid, you will either get magic juice, which increases your strength by |A[i][j]| points, or poison, which takes away |A[i][j]| strength points. If at any point of the journey, the strength points become less than or equal to zero, then you will die.
// You have to start from the top-left corner cell (1,1) and reach at the bottom-right corner cell (R,C). From a cell (i,j), you can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and you can not move outside the magic grid. You have to find the minimum number of strength points with which you will be able to reach the destination cell.
// Input format:
// The first line contains the number of test cases T. T cases follow. Each test case consists of R C in the first line followed by the description of the grid in R lines, each containing C integers. Rows are numbered 1 to R from top to bottom and columns are numbered 1 to C from left to right. Cells with A[i][j] < 0 contain poison, others contain magic juice.
// Output format:
// Output T lines, one for each case containing the minimum strength you should start with from the cell (1,1) to have a positive strength through out his journey to the cell (R,C).
// Constraints:
// 1 ≤ T ≤ 5
// 2 ≤ R, C ≤ 500
// -10^3 ≤ A[i][j] ≤ 10^3
// A[1][1] = A[R][C] = 0
// Time Limit: 1 second
// Sample Input 1:
// 3
// 2 3
// 0 1 -3
// 1 -2 0
// 2 2
// 0 1
// 2 0
// 3 4
// 0 -2 -3 1
// -1 4 0 -2
// 1 -2 -3 0
// Sample Output 1:
// 2
// 1
// 2

#include <bits/stdc++.h>
using namespace std;

int min_health(int **input,int r,int c){
    
    int **output = new int*[r];
    for(int i=0;i<r;i++){
        output[i] = new int[c] ;
    }
 
    output[r-1][c-1] = 1;
    for(int i = r-2;i>=0;i--){
        output[i][c-1] = max(1,output[i+1][c-1] - input[i][c-1]);
    }
    
    for(int j = c-2 ; j>=0 ;j--){
        output[r-1][j] = max(1,output[r-1][j+1] - input[r-1][j]) ;
    }
    
    for (int i=r-2; i>=0; i--) 
    { 
        for (int j=c-2; j>=0; j--) 
        { 
            output[i][j] = max(min(output[i+1][j], output[i][j+1]) - input[i][j], 1); 
        } 
     } 

    
    return output[0][0] ;
    
    
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int r,c;
        cin>>r>>c;
        int **magrid = new int*[r];
        for(int i=0;i<r;i++){
            magrid[i] = new int[c] ;
        }
        for(int i = 0 ;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>magrid[i][j];
            }
        }
        
        cout<<min_health(magrid,r,c)<<endl;
    }
    return 0;
}
