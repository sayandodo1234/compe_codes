// Given the value of N, you will have to find the value of G. The meaning of G is given in the following code
// G=0;
// for(i = 1 ; i < N ; i++)
//   for(j = i+1 ; j <= N ; j++) 
//       G+=gcd(i,j);
// Here gcd() is a function that finds the greatest common divisor of the two input numbers.
// Input
// The input file contains at most 20000 lines of inputs. Each line contains an integer N (1 < N < 1000001). The meaning of N is given in the problem statement. Input is terminated by a line containing a single zero.
// Output
// For each line of input produce one line of output. This line contains the value of G for the corresponding N. The value of G will fit in a 64-bit signed integer.
// Sample Input:
// 10
// 100
// 200000
// 0
// Sample Output:
// 67
// 13015
// 143295493160

#include <bits/stdc++.h>
using namespace std;

long long totient[1000001];
long long myResult[1000001];
long long myAnswer[1000001];

void preSolve()
{
	long long i,j;
	for(int i=1;i<1000001;i++)
		totient[i] = i;

	// Obtaining Euler Totient
	for(i=2;i<1000001;i++)
	{
		if(totient[i] == i)
		{
			for(j=i;j<1000001;j+=i)
			{
				totient[j] /= i;
				totient[j]*=i-1;
			}
		}
	}

	for(i=1;i<1000001;i++)
	{
		for(j=i;j<1000001;j+=i)
			myResult[j] = myResult[j] + (i*totient[j/i]);
	}

	for(i=1;i<1000001;i++)
		myResult[i] -=i;
	myAnswer[0] = 0;

	for(i=1;i<1000001;i++)
		myAnswer[i] = myAnswer[i-1]+myResult[i];
}


int main()
{
	preSolve();
	long long N,G, i, j;
	while(1)
	{
		scanf("%lld", &N);
		if (N==0)
			break;
		printf("%lld\n", myAnswer[N]);
	}
}