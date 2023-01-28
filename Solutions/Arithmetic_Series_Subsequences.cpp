#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include<numeric>
int main()
{
    int N , D ,M;
    cin >> N>> D >> M;
    vector<int>arr;
    for(int i =0 ; i< N;i++)
    {
        int x;
        cin >>x;
        arr.push_back(x);
    }
    int count =0;
    unordered_map<int, vector <int>> U;
    for (int i = 0; i < N; i++)
    {
        auto it = U.find(arr[i]);
        if (it != U.end())
            U[arr[i]].push_back(i);
        else
        {
            vector <int>v;
            v.push_back(i);
            U.insert({ arr[i] , v });
        }
    }

    for (auto i = U.begin(); i != U.end(); i++)
    {   
        int key = i->first;
        if(M==2)
        {
            key+=D;
            auto it = U.find(key);
            if (it != U.end())
            {
                for(int k = 0 ; k <it->second.size() ; k++)
                    for(int c = 0 ; c<i->second.size();c++ )
                        {
                            if(it->second[k]>i->second[c])
                                count++;
                        }
            }
        }
        if(M==3)
        {
            key+=D;
            auto itOne = U.find(key);
            key+=D;
            auto itTwo = U.find(key);
            
            if(itOne != U.end()&&itTwo != U.end())
            {
                for(int j =0 ;j<itTwo->second.size();j++ )
                    for(int k = 0 ; k <itOne->second.size() ; k++)
                        for(int c = 0 ; c<i->second.size();c++ )
                        {
                            if(itTwo->second[j]>itOne->second[k]&&itOne->second[k]>i->second[c])
                                count++;
                        }
            }
        }      
    }
    cout << count;
    return 0;
}