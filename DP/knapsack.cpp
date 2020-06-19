//to implement 0/1 knapsack problem through dynamic programming
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
  int profit[5] = {0,1,2,5,6};  //profit of the objects
  int wt[5] = {0,2,3,4,5};      //weight of the objects
  int m = 8;                    //total capacity of the knapsack
  int n = 4;                    //total objects
  int ans[5][9];
  for (int i=0; i<=n; i++){
    for(int w=0; w<=m; w++){
      if((i==0) || (w==0))
        ans[i][w] = 0;
      else if(wt[i]<=w)
        ans[i][w] = max((profit[i] + ans[i-1][w-wt[i]]), ans[i-1][w]);
      else
        ans[i][w] = ans[i-1][w];
    }
  }
  cout<<"Maximum profit: "<<ans[n][m]<<endl;
  int i=n,j=m;
  cout<<"The following objects are allowed: "<<endl;
  while(i>=1 && j>=0){
    if(ans[i][j] == ans[i-1][j]){
      cout<<i<<"=0 "<<endl;
      i--;
    }
    else{
      cout<<i<<"=1 "<<endl;
      j = j - wt[i];
      i--;
    }
  }
  return 0;
}
