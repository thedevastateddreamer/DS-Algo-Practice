//implementing longest increasing subsequence having maximum sum
#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

//YEH FUNC KA LOGIC GADBAD HAI
void printSolution(int sol[],int dp[],int arr[],int index)
{
  int start = index;
  cout<<"The longest sequence is:"<<arr[index]<<" ";
  while(index>=0){
    int temp = sol[index];
    cout<<arr[temp]<<" ";
    index = temp;
  }
  cout<<endl;
  return;
}

int maxSumSubsequence(int arr[], int n)
{
  int dp[n],sol[n];
  for(int i=0;i<n;i++){
    dp[i] = arr[i];
    sol[i] = i;
  }
  for(int i=1;i<=n;i++){
    for(int j=0;j<i;j++){
      if(arr[i] > arr[j]){
        dp[i] = max(dp[i],dp[j]+arr[i]);
        sol[i] = j;
      }
    }
  }
  int maxi = dp[0];
  int index = -1;
  for(int i=1;i<=n;i++){
    if(maxi<dp[i]){
      maxi = dp[i];
      index = i;
    }
  }
  printSolution(sol,dp,arr,index);
  return maxi;
}

int main()
{
  int n;
  cout<<"Enter the size of the array:";
  cin>>n;
  int *arr = new int[n];
  cout<<"Enter the array:";
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int ans = maxSumSubsequence(arr,n);
  cout<<"\nThe maximum sum is:\n"<<ans<<endl;
  return 0;
}
