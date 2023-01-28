#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
void GetStrings(int M ,  int N ,int K ,string s , vector <string>StringList , int &MyAnswer  )
{
    if (s.length()==N)
    {
        int count = 0;
        for (int i = 0 ; i <M ; i++)
            if (s.find(StringList[i])!=string::npos)
                count++;
        if(count>=K)
            MyAnswer++;
        return;
    }
            GetStrings(M , N ,K ,s+'A' , StringList  ,MyAnswer);
            GetStrings(M , N ,K ,s+'B' , StringList  ,MyAnswer);
            GetStrings(M , N ,K ,s+'C' , StringList  ,MyAnswer);
            GetStrings(M , N ,K ,s+'D' , StringList  ,MyAnswer);    
            GetStrings(M , N ,K ,s+'E' , StringList  ,MyAnswer);
}
        

int main() {
    int M,N,K;
    cin>>M>>N>>K;
    vector <string>StringList(M);
    for(int i =0 ; i <M ;i++)
        cin>>StringList[i];
    int MyAnswer=0;
    
    GetStrings(M , N ,K ,"" , StringList  ,MyAnswer);
    cout<<MyAnswer;
    return 0;
}


