#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

long long MyFunc(vector<vector<long long>> matrix, int N, int M, vector<vector<long long>>&dp ,int i, int j)
{
    if(i==N-1&&j==M-1)
        return dp[i][j]=1;
    if(dp[i][j]==-1)
    {
        if(matrix[i][j]==-1)
            return 0;
        dp[i][j]=0;
        if(i+1<=N-1)
            {
                dp[i][j]+=MyFunc(matrix,N,M,dp,i+1,j);
            }
            if(j+1<=M-1 )
            {
                dp[i][j]+=MyFunc(matrix,N,M,dp,i,j+1);
            }
    }
        return dp[i][j];
}

int main() {
    int n , m;
    cin >>n >> m;
    vector<vector<long long>> matrix(n,vector<long long>(m));
      for (int j = 0; j< n ; j++)
            for (int k = 0; k < m; k++)
            {
                int X;
                cin >> X;
                matrix[j][k] = X;
            }
    vector<vector<long long>> dp(n,vector<long long>(m,-1));
    MyFunc(matrix, n, m, dp,0,0);
    cout<<dp[0][0];
    return 0;
}
