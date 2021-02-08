// Maximum XOR Subarray
// Send Feedback
// Given an array of n integers, find subarray whose xor is maximum.
// Input Format
// First line contains single integer n (1<=n<=1000000).
// Next line contains n space separated integers.
// Output Format
// Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.
// Constraints
// 1 <= n <= 1000000
// 1 <= A[i] <=100000 
// Sample Input
// 4
// 1 2 3 4
// Sample Output
// 7
#include<bits/stdc++.h> 
using namespace std; 

class TrieNode{
    public:
    int value ;
    TrieNode *arr[2] ;
} ;

// Inserts pre_xor to trie with given root 
void insert(TrieNode *root, int pre_xor) 
{ 
	TrieNode *temp = root; 

	// Start from the msb, insert all bits of 
	// pre_xor into Trie 
	for (int i=31; i>=0; i--) 
	{ 
		// Find current bit in given prefix 
		bool val = pre_xor & (1<<i); 

		// Create a new node if needed 
		if (temp->arr[val] == NULL) {
			// temp->arr[val] = newNode(); 
            temp->arr[val] = new TrieNode ;
        }

		temp = temp->arr[val]; 
	} 

	// Store value at leaf node 
	temp->value = pre_xor; 
} 

int main() 
{ 
    int n ;
    cin>>n ;
    int a[n] ;
    
    TrieNode *root = new TrieNode ;
	insert(root, 0); 
	int result = INT_MIN, pre_xor =0; 
    
    for(int i = 0 ; i<n ; i++){
        cin>>a[i] ;
		pre_xor = pre_xor^a[i]; 
		insert(root, pre_xor); 
        
        
        TrieNode *temp = root; 
	    for (int i=31; i>=0; i--) {
            
            
		// Find current bit in given prefix 
		    bool val = pre_xor & (1<<i); 

		// Traverse Trie, first look for a 
		// prefix that has opposite bit 
		    if (temp->arr[1-val]!=NULL) {
			    temp = temp->arr[1-val]; 
            }

		// If there is no prefix with opposite 
		// bit, then look for same bit. 
		    else if (temp->arr[val] != NULL) 
			   temp = temp->arr[val]; 
	    } 
        int curr_xor = pre_xor^(temp->value) ;
        
		result = max(result, curr_xor) ;
        
        
    }
    cout<<result;
	return 0; 
} 



