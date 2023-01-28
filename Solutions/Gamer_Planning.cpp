#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main()
{
    int n;
    cin >> n;
    int max = 0;
    vector<long long>arr1;
    for(int i = 0; i<n ; i++)
    {
        long long x;
        cin >>x;
        arr1.push_back(x);
        if(x>max)
            max=x;
    }
    vector<long long>arr2;
    for(int i = 0; i<n ; i++)
    {
        long long x;
        cin >>x;
        arr2.push_back(x);
    }
    vector< pair <long long,long long>> vec;
    for(int i = 0; i<n ; i++)
    {
         vec.push_back( make_pair(arr2[i],arr1[i]) );
    }
    long long penalty = 0;
    sort(vec.begin(),vec.end());
    vector<long long>table(max,0);
    for(int i = n-1 ; i >=0 ; i--)
    {
        bool put=false;
        for(long long j = (vec[i].second)-1 ; j >=0 ; j--)
        {
            if(table[j]==0)
            {
                table[j]=vec[i].first;
                put=true;
                break;
            }
                    
        }
        if(put ==false)
            penalty+=vec[i].first;
    }
   cout<<penalty;
    return 0;
}