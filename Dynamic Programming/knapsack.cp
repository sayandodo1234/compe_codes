// Knapsnack - Problem
// Send Feedback
// A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.
// Note
// Space complexity should be O(W).
// Input Format :
// The first line contains an integers, that denote the value of N. The following line contains N space separated integers, that denote the values of weight of items. The following line contains N space separated integers, that denote the values associated with the items. The following line contains an integer that denote the value of W. W denotes maximum weight that thief can carry.
// Output Format :
// The first and only line of output contains the maximum value that thief can generate, as described in the task. 
// Constraints
// 1 <= N <= 10^4
// 1<= wi <= 100
// 1 <= vi <= 100
// Time Limit: 1 second
// Sample Input 1 :
// 4
// 1 2 4 5
// 5 4 8 6
// 5
// Sample Output 1 :
// 13

int knapsack(int* weights, int* values, int n, int maxWeight){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
    

    
    int arr1[maxWeight+1];
    int arr2[maxWeight+1];
    
    for(int i = 0 ; i<=maxWeight;i++){
        arr1[i] = 0;
        arr2[i] = 0;
    }
    
    int buff = n;
    for(int i = 0;i<=n;i++){
        for(int j = 1 ; j<= maxWeight ; j++){
            arr2[j] = arr1[j] ;
            if(weights[i-1] <= j){
                arr2[j] = max(values[i-1] + arr1[j-weights[i-1]],arr2[j]) ;
            }

        }
        for(int k = 1 ; k<=maxWeight ; k++){
            arr1[k] = arr2[k] ;
        }
    }
    
    return arr2[maxWeight] ;


}
