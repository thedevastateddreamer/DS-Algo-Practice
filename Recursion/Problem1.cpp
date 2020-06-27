/*
PRINT ALL POSSIBLE STRINGS (AMAZON)
Level: Basic
Given a string str your task is to complete the function printSpaceString which takes only one argument the string str and  prints all possible strings that can be made by placing spaces (zero or one) in between them.

For eg .  for the string abc all valid strings will be
                abc
                ab c
                a bc
                a b c


Input:
The First line of input takes an integer T denoting the number of test cases . Then T test cases follow . Each line of test case contains a string str .

Output:
For each test case output the strings possible in a single line  separated by a "$"

The Task:
Complete the function printSpace() which takes a character array as an input parameter and print all possible answers. The new line will be added by driver code only, you don't need to print a newline.

Expected Time Complexity: O(N * 2N)
Expected Auxiliary Space: O(N)


Constraints:
1<=T<=100
1<= length of string str <=10

Example:
Input
2
abc
xy
Output
abc$ab c$a bc$a b c$
xy$x y$


Explanation:
Test Case 1: Explained in the above statement.
Test Case 2: There are two possibilities, xy and x y.

*/
#include<iostream>
#include<string.h>
using namespace std;

void printSpace(char str[]);
int main()
{
    int t; cin>>t;
    while(t--){
        char str[10000];
        cin>>str;
        printSpace(str);
        cout<<endl;
    }
    return 0;
}
/*You have to complete this function*/
void solve(char str[],string ans, int ind, bool flag)
{
    if(str[ind] == '\0'){
        cout<<ans<<"$";
        return ;
    }
    else{
        solve(str,ans + str[ind], ind+1,true);
        if(flag == true)    //the previous char added was not space
          solve(str,ans + " ",ind,false);
    }
}
void  printSpace(char str[])
{
    //Your code here
    string ans = "";
    ans += str[0];
    solve(str,ans,1,true);
}
