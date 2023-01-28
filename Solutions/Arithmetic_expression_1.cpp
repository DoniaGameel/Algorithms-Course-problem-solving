#include<iostream>
using namespace std;
#include <vector>
void MyFunc(vector<int> MyNumbers, vector<bool> IsSelected, bool& Possible, int calc , int index)
{
    
    if (index == MyNumbers.size())
    {
        if (calc == 27)
        {
            Possible = true;
        }
        return;
    }

        
    for (int i =0;i < MyNumbers.size(); i++)
    {
        if (IsSelected[i] == false &&Possible==false )
        {
            IsSelected[i] = true;
            MyFunc(MyNumbers, IsSelected, Possible, calc + MyNumbers[i], index+1);
            if(index!=0)
            MyFunc(MyNumbers, IsSelected, Possible, calc - MyNumbers[i],index+1);
            if(index!=0)
            MyFunc(MyNumbers, IsSelected, Possible, calc * MyNumbers[i], index + 1);
            IsSelected[i] = false;
        }
        
    }
    
    
}


int main() 
{
    vector<int> MyNumbers;
    int x;
    for (int i = 0; i < 5; i++)
    {
        cin >> x;
        MyNumbers.push_back(x);
    }
    bool possible = false;
    vector<bool> IsSelected(5, false);
    MyFunc(MyNumbers, IsSelected, possible,0, 0);
    if (possible == true)
        cout << "Possible";
    else
        cout << "Impossible";
    return 0;
}