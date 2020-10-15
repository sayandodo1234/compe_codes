
// O(W) space complexity solution
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
