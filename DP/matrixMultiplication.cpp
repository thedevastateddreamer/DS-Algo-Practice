//to minimise cost of matrix chain multiplication using DP
//A1 X A2 X A3 X A4
//(5,4)(4,6)(6,2)(2,7)

#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

void printParenthesis(int i,int j,int n,int *s,char &name)
{
  if(i == j){
    cout<<name++;
    return;
  }
  cout<<"(";
  printParenthesis(i, *((s+i*n)+j),n,s,name);

  // Recursively put brackets around subexpression from s[i][j] + 1 to j.
  printParenthesis(*((s+i*n)+j) + 1,j,n,s,name);
  cout<<")";
}
int main()
{
  int n = 5;
  int p[] = {5,4,6,2,7};
  int m[5][5] = {0};
  int s[5][5] = {0};
  int j, min, q=0;
  for(int d=2; d<n; d++){
    for(int i=1; i<n-d+1; i++){
      j = i+d-1;
      min = INT_MAX;
      for(int k=i; k<=j-1; k++){
        q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
        if(q<min){
          min = q;
          s[i][j] = k;
        }
      }
      m[i][j] = min;
    }
  }
 cout<<endl<<"Minimum cost of multiplying the matrices:"<<endl;
 cout<<m[1][n-1]<<endl;
 cout<<"Optimal paranthesis:"<<endl;
 char name = 'A';
 printParenthesis(1,4,5,(int*)s,name);
 return 0;

}
