/* Given different dimensions, stack boxes on each other such that it has maximum height but
length and width of box on top should be strictly less than the box underneath it.
We can rotate the boxes as we like.
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct compute
{
    int l;
    int w;
    int h;
};

bool s(compute a, compute b)
{
    return a.l*a.w <b.l*b.w;
}

int maxHeight(int height[],int width[],int length[],int n)
{
    compute arr[3*n]; int j=0; int i=0;
    while(j < 3*n)
    {
        arr[j].h=height[i];
        arr[j].w = min(width[i], length[i]);
        arr[j].l = max(width[i], length[i]);
       j++;
        arr[j].h=width[i];
        arr[j].w = min(height[i], length[i]);
        arr[j].l = max(height[i], length[i]);
       j++;
        arr[j].h=length[i];
        arr[j].w = min(width[i], height[i]);
        arr[j].l = max(width[i], height[i]);
        j++;
        i++;
    }


    sort(arr,arr+3*n, s);
    int dp[3*n];
    for(int i=0; i<3*n; i++)
    {
        dp[i]=arr[i].h;
    }
    for(int i=1; i<3*n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i].w>arr[j].w && arr[i].l > arr[j].l
            && dp[i] < dp[j]+arr[i].h)
            {
                dp[i]=dp[j]+arr[i].h;
            }
        }

    }
    int count = 0;
    for(int i=0; i<3*n; i++)
    {
        if(dp[i]>count){count=dp[i];}
    }
    return count;
}
int main()
{
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int A[1000], B[1000], C[10001];
    for(int i=0;i<n;i++){
      int a,b,c;
      cin>>a>>b>>c;
      A[i] = a;
      B[i] = b;
      C[i] = c;
    }
    cout<<maxHeight(A,B,C,n)<<endl;
  }
  return 0;
}
