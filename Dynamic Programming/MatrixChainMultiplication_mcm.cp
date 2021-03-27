/******************************************************************************
                            Matrix Chain multiplication
                             A1  X  A2  X  A3  X  A4
                           (5 X 4) (4 X 6) (6 X 2) (2 X 7)
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5 ;
    int P[] = {5,4,6,2,7};
    int m[5][5] = {0} ;
    int s[5][5] = {0} ;
    int q ;
    for(int d = 1 ; d< n-1 ; d++){ 
        for(int i = 1;i<n-d ; i++){
            int j = i+d; 
            int min = 1e6 ;
            for(int k = i ; k<= j-1 ; k++){
                q = m[i][k] + m[k+1][j] + (P[i-1]*P[k]*P[j]) ;
                if(q<min){
                    min = q ;
                    s[i][j]=k ;
                }
                
            }
            m[i][j] = min ;
        }
    }

    return 0;
}
// d is the difference between end and last element i.e if d = 1 then m[1,2] m[2,3] m[3,4] .
// j is the end for instance we are formulating for m[1,3] where j is 3 (i = 1 and d = 2) .
// For instance , we are calculating m[1,3] then j is 3 .
// k breaks down j into multiple parts.
// For instance , 
// for i = 1 for k = 1 k<=j-1 i.e 2 , then m[1,3] = m[1,1] + m[2][3] + (P[0] * P[1] * P[3])
// for same i and j only when k is incremented the k = 2 hence, this will be the last time 
// the inner loop(third loop) will be used for this .  m[1,3] = m[1,2] +m[3][3] +(P[0]*P[2]*P[3])