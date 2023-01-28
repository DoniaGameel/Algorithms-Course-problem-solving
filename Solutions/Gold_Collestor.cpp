#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
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

long long MyFunc(vector<vector<long long>> matrix, int N, int M, vector<vector<long long>> dp)
{
    for(int i=N-1 ; i >=0 ; i--)
        for(int j = M-1 ; j >=0;j--)
        {
            if(dp[i][j]==LLONG_MIN)
            {
                if(i==N-1 && j==M-1)
                     dp[i][j]=matrix[i][j];
                else if(i==N-1 )
                     dp[i][j]=matrix[i][j]+dp[i][j+1];
                else if(j==M-1)
                     dp[i][j]=matrix[i][j]+dp[i+1][j];
                else
                    dp[i][j]=matrix[i][j]+getMax(dp[i+1][j],dp[i][j+1],dp[i+1][j+1]);
            }
        }
   
    return dp[0][0];
}

int main() {
    int n , m;
    cin >>n >> m;
    vector<vector<long long>> matrix(n,vector<long long>(m));
      for (int j = 0; j< n ; j++)
            for (int k = 0; k < m; k++)
            {
                long long X;
                cin >> X;
                matrix[j][k] = X;
            }
    vector<vector<long long>> dp(n,vector<long long>(m,LLONG_MIN));
   cout<<MyFunc(matrix, n, m, dp);
    return 0;
}
