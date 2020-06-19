/* Longest increasing subsequence using DP (they should be in an increasing sorted order)
3 4 -1 0 6 2 3 (ans= 4; -1,0,2,3)
2 5 1 8 3 (ans=3; 2,5,8)
*/

#include<iostream>
#include<algorithm>
using namespace std;

int longIncreasingSub(int arr[],int n)
{
  int DP[n];
  int sol[n];
  for(int i=0;i<n;i++){
    DP[i] = 1;
    sol[i] = i;  //storing the index
  }
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(arr[j] < arr[i]){
        DP[i] = max(DP[i],DP[j]+1);
        sol[i] = j;
      }
    }
  }
  int maxIndex = 0;   //finding index of max number in DP
  for(int i=0;i<n;i++){
    if(DP[i]>maxIndex)
      maxIndex = i;
  }
  //try to print the solution
  cout<<"\nThe solution is: ";
  int t = maxIndex;
  int newT = maxIndex;
  do{
    t = newT;
    cout<<arr[t]<<" ";
    newT = sol[t];
  }while(t != newT);
  cout<<endl<<endl;

  return DP[maxIndex];
}
int main()
{
  int n;
  cout<<"Enter the size of the array:";
  cin>>n;
  int arr[n];
  cout<<"Enter the array:";
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int res = longIncreasingSub(arr,n);
  cout<<"The longest increasing subsequence is:"<<res<<endl;

  return 0;
}
