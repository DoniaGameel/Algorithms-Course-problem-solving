#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void MyFunc(vector<string>MyVector, string MyString, int index, int& count, vector <bool>IsSelected, int MyLength)
{
    if (index == MyVector.size())
    {
        if (MyString.length() == MyLength)
        {
            count++;
        }
        return;
    }

    for (int i = 0; i < MyVector.size(); i++)
    {
        if (IsSelected[i] == false)
        {
            if (MyString.length() != 0)
            {
                int L = MyString.length();
                if (MyString[L - 1] == MyVector[i][0])
                    continue;
            }

            IsSelected[i] = true;
            MyFunc(MyVector, MyString + MyVector[i], index + 1, count, IsSelected, MyLength);
            IsSelected[i] = false;
        }


    }
}

int main()
{
    int N;
    cin >> N;
    vector<string>MyVector;
    vector<bool>IsSelected(N, false);
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        MyVector.push_back(s);
    }
    int MyLength = 0;
    for (int i = 0; i < MyVector.size(); i++)
    {
        MyLength += MyVector[i].length();
    }
    
    int count = 0;
    MyFunc(MyVector, "", 0, count, IsSelected, MyLength);
    cout << count;
    return 0;
}