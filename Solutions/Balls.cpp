#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int S,A,B;
    cin>>S>>A>>B;
    int remainder, Bcount;
    int MinRemainder,optimalA,optimalB;
    int    Acount=optimalA=0;
    optimalB=Bcount=S/B;
    remainder=MinRemainder=S%B;
    while(remainder!=0&&(S>=A))
    {
        S-=A;
        Acount++;
        Bcount=S/B;
        remainder=S%B;
        if(remainder<MinRemainder )
        {
            MinRemainder=remainder;
            optimalB=Bcount;
            optimalA=Acount;
        }
    }

    cout<<optimalA<<" "<<optimalB<< " " <<MinRemainder;
    return 0;
}
