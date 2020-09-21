// As you might remember, the collector of Siruseri had ordered a complete revision of the Voters List. He knew that constructing the list of voters is a difficult task, prone to errors. Some voters may have been away on vacation, others may have moved during the enrollment and so on.

// To be as accurate as possible, he entrusted the task to three different officials. Each of them was to independently record the list of voters and send it to the collector. In Siruseri, every one has a ID number and the list would only list the ID numbers of the voters and not their names. The officials were expected to arrange the ID numbers in ascending order in their lists.

// On receiving the lists, the Collector realised that there were discrepancies - the three lists were not identical. He decided to go with the majority. That is, he decided to construct the final list including only those ID numbers that appeared in at least 2 out of the 3 lists. For example if the three lists were

// 23  30  42  57  90
// 21  23  35  57  90  92
// 21  23  30  57  90 
// then the final list compiled by the collector would be:

// 21  23  30  57  90
// The ID numbers 35, 42 and 92 which appeared in only one list each do not figure in the final list.

// Your task is to help the collector by writing a program that produces the final list from the three given lists.

// Input format

// The first line of the input contains 3 integers N1, N2 and N3. N1 is the number of voters in the first list, N2 is the number of voters in the second list and N3 is the number of voters in the third list. The next N1 lines (lines 2,...,N1+1) contain one positive integer each and describe the first list in ascending order. The following N2 lines (lines N1+2,...,N1+N2+1) describe the second list in ascending order and the final N3 lines (lines N1+N2+2,...,N1+N2+N3+1) describe the third list in ascending order.

// Output format

// The first line of the output should contain a single integer M indicating the number voters in the final list. The next M lines (lines 2,...,M+1) should contain one positive integer each, describing the list of voters in the final list, in ascending order.

// Test data

// You may assume that 1 ≤ N1,N2,N3 ≤ 50000.

// Example

// Sample input:

// 5 6 5
// 23
// 30
// 42
// 57
// 90
// 21 
// 23 
// 35 
// 57 
// 90 
// 92 
// 21 
// 23 
// 30 
// 57 
// 90 
// Sample output:

// 5
// 21 
// 23 
// 30 
// 57 
// 90










#include<bits/stdc++.h>
using namespace std;

void arr_insert(int *arr,int size)
{
    for(int i=0;i<size;i++)
     cin>>arr[i];

    return ;
}
int main(void)
{
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    map<int,int> m;
    int *arr1=new int[n1];
    int *arr2=new int[n2];
    int *arr3=new int[n3];
    int *arr = new int[n1+n2+n3];
    arr_insert(arr1,n1);
    arr_insert(arr2,n2);
    arr_insert(arr3,n3);
    copy(arr1, arr1 + n1, arr);
    copy(arr2, arr2 + n2, arr + n1);
    copy(arr3, arr3 + n3, arr + n1 + n2);
    sort(arr,arr+n1+n2+n3);
    for(int i=0;i<(n1+n2+n3);i++)
    {
        m[arr[i]]++;
    }
    map<int,int> :: iterator it;
    // set<int> :: iterator sit;
    // set<int> s;
    int count = 0 ;
    for(it=m.begin();it != m.end();it++)
    {
        if(it->second >1)
        {
            (it->first);
            count++;
        }   
    }
    cout<<count<<endl;
    for(it=m.begin();it != m.end();it++)
    {
        if(it->second >1)
        {
            cout<<it->first<<endl;
            count++;
        }   
    }




}