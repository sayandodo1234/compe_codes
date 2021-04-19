// In a class there are ‘n’ number of students. They have three different subjects: Data Structures, Algorithm Design & Analysis and Operating Systems. Marks for each subject of all the students are provided to you. You have to tell the position of each student in the class. Print the names of each student according to their position in class. Tie is broken on the basis of their roll numbers. Between two students having same marks, the one with less roll number will have higher rank. The input is provided in order of roll number.
// Input Format:
// First line will have a single integer ‘n’, denoting the number of students in the class.
// Next ‘n’ lines each will have one string denoting the name of student and three space separated integers m1, m2, m3 denoting the marks in three subjects.
// Output Format:
// Print ‘n’ lines having two values: First, the position of student in the class and second his name.
// Constraints:
// 1 <= n <= 10^5
// 0 <= m1, m2, m3 <= 100
// Sample Input:
// 3
// Mohit 94 85 97
// Shubham 93 91 94
// Rishabh 95 81 99
// Sample Output:
// 1 Shubham
// 2 Mohit
// 3 Rishabh

#include<bits/stdc++.h>
using namespace std;
class Student
{
    public :
    string names;
    int marks;
    int roll_no;
};
bool marks_sort(Student s1,Student s2)
{
    if(s1.marks != s2.marks)
        return s1.marks >s2.marks ;
    return s1.roll_no < s2.roll_no ;
}
int main()
{
    int n;
    cin>>n;
    //string names[n];
    Student S[n];
    int m1,m2,m3;
    // pair<string,vector<int>> p;
    //vector<pair<string,int>> v;
    for(int i=0;i<n;i++)
    {
        cin>>S[i].names>>m1>>m2>>m3;
        S[i].marks = m1+m2+m3 ;
        S[i].roll_no =i+1;
    }
    sort(S,S+n,marks_sort);
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<" "<<S[i].names<<endl;
    }
    
	return 0;
}
