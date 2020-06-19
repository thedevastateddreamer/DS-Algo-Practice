/* Given two strings- edit, delete,add; How many min operations to convert one string to other
abcdef
azced
ans= 3
*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int min(int x, int y, int z)
{
  return min(min(x,y),z);
}
string str1,str2;

void printSolution(string str1, string str2, int DP[str1.length()][str2.length()])
{
      int i = str1.length() - 1;
      int j = str2.length() -1;

      while(true){
        if(i==0 || j==0)
          break;
        if(str1[i] == str2[j]){
          i--;j--;
        }
        else if(DP[i][j] == 1+DP[i-1][j-1]){
          cout<<"Edit "<<str2[j-1]<<" in string2 to "<<str1[i-1]<<" in string1"<<endl;
          i--;j--;
        }
        else if(DP[i][j] == 1+DP[i-1][j]){
          cout<<"Delete in string1 "<<str1[i-1]<<endl;
          i--;
        }
        else if(DP[i][j] == DP[i][j-1]+1){
          cout<<"Delete in string2 "<<str2[j-1]<<endl;
          j--;
        }
      }
}


int minEdit(string str1, string str2)
{
  int len1 = str1.length();
  int len2 = str2.length();
  int DP[len1+1][len2+1];
  for(int i=0;i<=len1;i++){
    for(int j=0;j<=len2;j++){
      if(i == 0)
        DP[i][j] = j;
      else if(j == 0)
        DP[i][j] = i;
      else if(str1[i-1] == str2[j-1])
        DP[i][j] = DP[i-1][j-1];
      else
        DP[i][j] = 1 + min(DP[i][j-1],DP[i-1][j],DP[i-1][j-1]);     //insert,remove,replace
    }
  }
  printSolution(str1,str2,DP);
  return DP[len1][len2];
}



int main()
{
  //string str1,str2;
  cout<<"Enter str1:";
  cin>>str1;
  cout<<"Enter str2:";
  cin>>str2;
  int res = minEdit(str1,str2);
  cout<<"Minimum edits required:"<<res<<endl;
  return 0;
}
