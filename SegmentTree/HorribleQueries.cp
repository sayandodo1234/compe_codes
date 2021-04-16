// World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
// 0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.

// 1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
// Input
// In the first line you'll be given T, number of test cases.

// Each test case will start with N (N <= 100 000) and C (C <= 100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p, q <= N and 1 <= v <= 10^7.
// Output
// Print the answers of the queries.
// Input:
// 1
// 8 6
// 0 2 4 26
// 0 4 8 80
// 0 4 5 20
// 1 8 8 
// 0 5 7 14
// 1 4 8
// Output:
// 80  
// 508

// #include<bits/stdc++.h>
// using namespace std;
// int main() {

// 	// Write your code here
// }

#include<iostream>
#include<string.h>
long long int arr[1000005],seg[10000005],lzy[10000005];
using namespace std;
#define inf 100000001
 int ups,upe,qs,qe;//qs = query start index , qe= query end index   
 long long int val;// ups = update start index , upe =update end index
 long long  int qry(int index,int start,int end)
  {
     
       if(lzy[index]!=0)
        {
         seg[index]+=lzy[index]*(end-start+1);
         if(start!=end)
          {
           
        
           lzy[2*index]+=lzy[index];
           lzy[2*index+1]+=lzy[index];
          }
          lzy[index]=0;
        }
         if(start>end || end<qs || start>qe)
       {
        return 0;
       }
        if(start>=qs && end<=qe)
         {
          return  seg[index];
          
         }
        long long  int q1=qry(2*index,start,(start+end)/2);
        long long  int q2=qry(2*index+1,((start+end)/2)+1,end);
         return q1+q2;
   
  }
  
  
void update(int index,int start,int end)
{
  if(lzy[index]!=0)// means index contain some un updated range so update seg tree and  make its   child lazy if have child
   {
    seg[index]+=lzy[index]*(end-start+1);
    //  checking if having child than make it lzy
    if(start!=end)//  adding lzy[index] bcos making parent unlaxy and if parent have any child tnhan mak it lazy equal
                   // exactly to its parent amount .......
     {
        
          
           lzy[2*index]+=lzy[index];
           lzy[2*index+1]+=lzy[index];
     }
     lzy[index]=0;
     
   }
   if(start>end || start>upe || end<ups) return ;// if(range in complitly out of range sooo need not to update ;;;;)
   if(start>=ups && end<=upe)//     ( means if range (start and end ) is complitle within the update qry )...
    {
        seg[index]+=(end-start+1)*val;// just update the parent  and make its chile lzy so thate will be update latter
        if(start!=end)/// adding  only val sice it is new dew it is not propogating from parent
         {
         
         
           lzy[2*index]+=val;
           lzy[2*index+1]+=val;
         }
         return;
         
    }
    
     update(2*index,start,(start+end)/2);
     update(2*index+1,((start+end)/2)+1,end);
     
     seg[index]=seg[2*index]+seg[2*index+1];
  
 }
 
 

int main()
 {
  int t;
   cin>>t;
     while(t--)
      {
       
      
        int n,q;
      cin>>n>>q;
      memset(seg,0,10000001);
      memset(lzy,0,10000001);
         while(q--)
          {
            int qq;
            cin>>qq;
             if(qq==0)
              {
                cin>>ups>>upe>>val;
                ups-=1;
                upe-=1;
                update(1,0,n-1);
               
               
              }
              else
               {
                 cin>>qs>>qe;
                 qs-=1;
                 qe-=1;
                 long long int  ans=  qry(1,0,n-1);
                  cout<<ans<<endl;
                  
                 
               }
          
      
          }
      }
  return 0;
 }