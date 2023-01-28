#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int MyFunc(vector<vector<vector<int>>> matrix, int N,  int I ,int J ,int K , int&min, vector<vector<vector<int>>>&IsSelected)
{
    if (I == N - 1 && J == N - 1 && K == N - 1)
    {
        return IsSelected[I][J][K]=matrix[I][J][K];
    }
    if (IsSelected[I][J][K] == -1)
    {
        int sum1=INT_MAX;
        int sum2=INT_MAX;
        int sum3=INT_MAX;
        IsSelected[I][J][K]=matrix[I][J][K];
        if (I <= N - 2 )
        sum1=IsSelected[I+1][J][K]=MyFunc(matrix, N, I+1, J, K, min, IsSelected);
        if (J <= N - 2)
        sum2=IsSelected[I][J+1][K]=MyFunc(matrix, N,  I , J+1, K, min, IsSelected);
        if (K <= N - 2 )
        sum3=IsSelected[I][J][K+1]=MyFunc(matrix, N,  I , J, K+1, min, IsSelected);
        IsSelected[I][J][K] = matrix[I][J][K]+std::min(sum1,std::min(sum2,sum3));
    }
     return IsSelected[I][J][K];           
                
}

int main()
{
    int N;
    cin >> N;
    vector<vector<vector<int>>> matrix(N, vector<vector<int>>(N, vector<int >(N)));
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int >(N,-1)));
    int X;
    for (int i = 0; i < N; i++)
        for (int j = 0; j< N ; j++)
            for (int k = 0; k < N; k++)
            {
                cin >> X;
                matrix[i][j][k] = X;
            }
    int Min = 9999999;
    int Sum = 0;
    MyFunc(matrix, N, 0, 0, 0, Min, dp);
    cout << dp[0][0][0];
}