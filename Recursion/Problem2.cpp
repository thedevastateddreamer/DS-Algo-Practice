/*
NUMBER OF PATHS (AMAZON, MICROSOFT, ZOHO)
Level: Basic
The problem is to count all the possible paths from top left to bottom right of a MxN matrix with the constraints that from each cell you can either move to right or down.

Input:
The first line of input contains an integer T, denoting the number of test cases. The first line of each test case is M and N, M is number of rows and N is number of columns.

Output:
For each test case, print the number of paths.

Constraints:
1 ≤ T ≤ 30
1 ≤ M,N ≤ 10

Example:
Input
2
3 3
2 8

Output
6
8

Explanation:
Testcase 1: Let the given input 3*3 matrix is filled as such:
A B C
D E F
G H I
The possible paths which exists to reach 'I' from 'A' following above conditions are as follows:
ABCFI, ABEHI, ADGHI, ADEFI, ADEHI, ABEFI.
*/

#include<bits/stdc++.h>
using namespace std;
//int M[11][11];
int minPaths(int m,int n)
{
    if(m==1 || n==1)
      return 1;
    return minPaths(m-1,n) + minPaths(m,n-1);
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	int m,n;
	cin>>m>>n;
	cout<<minPaths(m,n)<<endl;
	}
	return 0;
}
