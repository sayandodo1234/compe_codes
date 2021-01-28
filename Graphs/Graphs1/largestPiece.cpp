// It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
// Input Format :
// The first line of input contains an integer, that denotes the value of N. 
// Each of the following N lines contain N space separated integers.
// Output Format :
// Print the count of '1's in the biggest piece of '1's, according to the description in the task.
// Constraints :
// 1 <= N <= 1000
// Time Limit: 1 sec
// Sample Input 1:
// 2
// 1 1
// 0 1
// Sample Output 1:
// 3

void dfs(vector<vector<int>> &cake, int n,int x,int y,bool **visited,int &count){

    count++ ;
    visited[x][y] = true ;
    // cake[x][y] = 0 ;
    
    if(x+1 < n && cake[x+1][y] == 1 && visited[x+1][y] != true){
        dfs(cake,n,x+1,y,visited,count) ;
    }
    if(y+1 < n && cake[x][y+1] == 1 && visited[x][y+1] != true){
        dfs(cake,n,x,y+1,visited,count) ;
    }
    if(y-1 >=0 && cake[x][y-1] == 1 && visited[x][y-1] != true){
        dfs(cake,n,x,y-1,visited,count) ;
    }
    if(x-1 >=0 && cake[x-1][y] == 1 && visited[x-1][y] != true){
        dfs(cake,n,x-1,y,visited,count) ;
    }

    
    
     return ;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    bool **visited = new bool*[n] ;
    for(int i = 0 ;i<n ; i++){
        visited[i] = new bool[n] ;
        for(int j = 0 ;j<n ; j++){
            visited[i][j] = false ;
        }
    }
    int ans = 0 ;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            if(cake[i][j] ==1){
                int count = 0 ;
                dfs(cake,n,i,j,visited,count) ;
                ans = max(ans,count) ;
            }
        }
    }
    return ans ;
}