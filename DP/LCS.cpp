/*Longest common subsequence using DP (not necessarily consecutive)
abcdaf
acbcf
ans = 4
*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int longestSubsequence(string str, string sub, int m, int n)
{
  int DP[m+1][n+1];
  int j,i;
  for(i=0;i<=m;i++){
    for(j=0;j<=n;j++){
      if(i==0 || j==0)
        DP[i][j] = 0;
      else if(str[i]==sub[j])
        DP[i][j] = DP[i-1][j-1] + 1;
      else
        DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
    }
  }

  return DP[m][n];
}

int main()
{
  string str,sub;
  cout<<"Enter string:";
  cin>>str;
  cout<<"Enter the subsequence:";
  cin>>sub;
  int m,n;
  m = str.length();
  n = sub.length();
  cout<<"The Longest Common Subsequence is:"<<longestSubsequence(str,sub,m,n)<<endl;

  return 0;
}
