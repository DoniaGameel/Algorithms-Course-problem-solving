#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long long getMax(long long a , long long b ,long long c)
{
    if(a>b)
    {
        if(a>c)
            return a;
        else
            return c;
    }
    else 
    {
        if(b>c)
            return b;
        else

        return c;
    }
}
long long MaxScore(vector<vector<long long>>arr ,int n)
{
    if(n==0)
        return 0;
    if(n==1)
    {
        if(arr[0][0]>arr[1][0])
            return arr[0][0];
        else 
            return arr[1][0];
    }
    vector<vector<long long>>dp(2, vector<long long> (n,-1));
    dp[0][0]=arr[0][0];
    dp[1][0]=arr[1][0];
    dp[0][1]=arr[0][1]+arr[1][0];
    dp[1][1]=arr[1][1]+arr[0][0];
    for(long long i = 2; i < n ; i++)
    { 
        dp[0][i]=arr[0][i]+getMax(dp[0][i-2],dp[1][i-1],dp[1][i-2]);
        dp[1][i]=arr[1][i]+getMax(dp[1][i-2],dp[0][i-1],dp[0][i-2]);
    }
    long long max = dp[0][n-2];
    if( dp[1][n-2]>max)
       max=dp[1][n-2];
    if( dp[0][n-1]>max)
        max=dp[0][n-1];
    if(dp[1][n-1]>max)
        max=dp[1][n-1];
    return max;
}

int main() {
    int n ;
    cin >>n;
    vector<vector<long long>>arr( 2, vector<long long> (n));
    for(int i = 0 ; i < 2 ; i ++)
        {
            for(long long j =0; j <n ; j++)
        {
            long long x;
            cin >>x;
            arr[i][j]=x;
        }
    }
    cout<<MaxScore(arr,n);
    return 0;
}
