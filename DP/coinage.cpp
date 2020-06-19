//Given a set of coins, no of coins and the total amount
//To minimise the no. of coins required to make up the amount

#include<iostream>
#include<algorithm>
#include<limits>
#include<math.h>

using namespace std;
void printCombination(int ans[],int amount, int coins[])
{
  int start = amount-1+1;
  cout<<endl<<"Coins used to form total:";
  while(start!=0)
  {
    int j = ans[start];
    cout<<coins[j]<<" ";
    start = start - coins[j];
  }
  //cout<<endl;
  return ;
}
int coinsNeeded(int coins[], int amount, int n)
{
  int dp[amount+1];
  int ans[amount+1];
  dp[0] = 0;
  for(int i=1;i<=amount;i++){
    dp[i] = INT_MAX - 1;
    ans[i] = -1;
  }
    for(int j=0;j<n;j++){
      for(int i=1;i<=amount;i++){
        if(i>=coins[j]){
          if((dp[i-coins[j]]+1) < dp[i]){
            dp[i] = 1 + dp[i-coins[j]];
            ans[i] = j;
        }

      }
    }
  }
  printCombination(ans,amount,coins);
  return dp[amount];
}
int main()
{
  int amount, n;
  cout<<"Enter the amount:";
  cin>>amount;
  cout<<"Enter the no. of coins:";
  cin>>n;
  int *coins = new int[n];
  cout<<"Enter the values of coins:";
  for(int i=0;i<n;i++)
    cin>>coins[i];
  cout<<endl<<"Total coins needed to make "<<amount<<" is:";
  int ans = coinsNeeded(coins,amount,n);
  cout<<endl<<"Total:"<<ans;
  return 0;
}
