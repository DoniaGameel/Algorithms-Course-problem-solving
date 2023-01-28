#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int solve(vector<int>& L, int i, int j,  vector<vector<int>>&memo)
{
    if(j-i==1)
        return 0;
    int min = INT_MAX;
    if(memo[i][j]<0)
    {
        for(int k = i+1 ; k < j ; k++)
    {
      int temp =L[j]-L[i]+solve(L,i,k,memo)+solve(L,k,j,memo);
      if (temp<min)
          min = temp;
    }
     return memo[i][j] =min;
    }
    else
        return memo[i][j];
   
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> L(M);

    for (int i = 0; i < M; i++)
    {
        cin >> L[i];
    }

    
    L.insert(L.begin(), 0);
    L.push_back(N);

    // TODO: declare DP storage and call it memo
    vector<vector<int>>memo( L.size(),vector<int>(L.size(),-1));
    // This function call is for guidance and you can change it if you want
   cout << solve(L, 0, L.size() - 1, memo) << endl;

    return 0;
}