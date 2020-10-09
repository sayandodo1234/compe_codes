// C. Jon Snow and his Favourite Number
// time limit per test4 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Jon Snow now has to fight with White Walkers. He has n rangers, each of which has his own strength. Also Jon Snow has his favourite number x. Each ranger can fight with a white walker only if the strength of the white walker equals his strength. He however thinks that his rangers are weak and need to improve. Jon now thinks that if he takes the bitwise XOR of strengths of some of rangers with his favourite number x, he might get soldiers of high strength. So, he decided to do the following operation k times:

// Arrange all the rangers in a straight line in the order of increasing strengths.
// Take the bitwise XOR (is written as ) of the strength of each alternate ranger with x and update it's strength.
// Suppose, Jon has 5 rangers with strengths [9, 7, 11, 15, 5] and he performs the operation 1 time with x = 2. He first arranges them in the order of their strengths, [5, 7, 9, 11, 15]. Then he does the following:
// The strength of first ranger is updated to , i.e. 7.
// The strength of second ranger remains the same, i.e. 7.
// The strength of third ranger is updated to , i.e. 11.
// The strength of fourth ranger remains the same, i.e. 11.
// The strength of fifth ranger is updated to , i.e. 13.
// The new strengths of the 5 rangers are [7, 7, 11, 11, 13]
// Now, Jon wants to know the maximum and minimum strength of the rangers after performing the above operations k times. He wants your help for this task. Can you help him?

// Input
// First line consists of three integers n, k, x (1 ≤ n ≤ 105, 0 ≤ k ≤ 105, 0 ≤ x ≤ 103) — number of rangers Jon has, the number of times Jon will carry out the operation and Jon's favourite number respectively.

// Second line consists of n integers representing the strengths of the rangers a1, a2, ..., an (0 ≤ ai ≤ 103).

// Output
// Output two integers, the maximum and the minimum strength of the rangers after performing the operation k times.

// Examples
// inputCopy
// 5 1 2
// 9 7 11 15 5
// outputCopy
// 13 7
// inputCopy
// 2 100000 569
// 605 986
// outputCopy
// 986 605



#include<bits/stdc++.h>
using namespace std;
#define N 100005
int freq[1100],tmp[1024];
int main()
{
	int n,k,maxm=0,minm=INT_MAX,p,x;
	cin>>n>>k>>x;
    for(int i = 0 ; i<n;i++){
        cin>>p;
        freq[p]++;
    }
	while(k--)
	{
		for(int i = 0;i<1024;i++){
            tmp[i]=freq[i];
        } 
		int par=0;
		for(int  i = 0;i<1024;i++)
		{
			if(freq[i]>0)
			{
				int curr = (i^x),change = (freq[i]/2);
				if(par==0) {
                    change+=(freq[i]&1);
                }
				tmp[i]-=change;
				tmp[curr]+=change;
				par^=(freq[i]&1);
			}
		}
        for(int i = 0 ; i<1024 ; i++){
            freq[i] = tmp[i] ;
        }
	}

    for(int i = 0 ; i<1024 ; i++){
        if(freq[i]>0){
            minm=min(minm,i),maxm=max(maxm,i);
        }
         
    }
	cout<<maxm<<" "<<minm;
	return 0;
}