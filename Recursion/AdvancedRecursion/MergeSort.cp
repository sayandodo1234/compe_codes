// Sort an array A using Merge Sort.
// Change in the input array itself. So no need to return or print anything.
// Input format :
// Line 1 : Integer n i.e. Array size
// Line 2 : Array elements (separated by space)
// Output format :
// Array elements in increasing order (separated by space)
// Constraints :
// 1 <= n <= 10^3
// Sample Input 1 :
// 6 
// 2 6 8 5 4 3
// Sample Output 1 :
// 2 3 4 5 6 8
// Sample Input 2 :
// 5
// 2 1 5 2 3
// Sample Output 2 :
// 1 2 2 3 5 

void merge(int a[],int start,int end,int mid)
{
    int *temp=new int[end-start+1];

	int i = start, k = 0 ,	j = mid + 1;


	while (i <= mid && j <= end)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <= end)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	for (i = start; i <= end; i++)
	{
		a[i] = temp[i-start];
	}


    
}

void mergeSort(int input[],int size,int start =0){
	// Write your code here
    // if (size == 0 || size == 1)
    //     return ;
    if(size == 0)
        return ;
    
    int end =size-1;

    if(start<end)
    {
        // int temp_l ;
        // int temp_r ;
        int mid = (start+end)/2; 
        
        mergeSort(input,mid+1,start);
        mergeSort(input,end+1,mid+1);
        merge(input,start,end,mid);
        
    }

    

        
}
