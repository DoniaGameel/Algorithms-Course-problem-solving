#include<iostream>
#include<vector>
#include<string>
using namespace std;

void StringReArrangements(bool&Found, vector<string>MyStrings, vector<string>MySwaps, int L, int index, int count, int& min)
{
    vector<string>TempVector;
    for (int i = 0; i < MyStrings.size(); i++)
        TempVector.push_back(MyStrings[i]);

    if (index == MySwaps.size())
        return;
    count = 0;
    for (int i = 0; i < MyStrings.size(); i++)
    {
        for (int j = 0; j < L; j++)
        {
            if (MyStrings[i] != MySwaps[index])
            {
                char temp1 = MyStrings[i][0];
                for (int k = 0; k < L - 1; k++)
                    MyStrings[i][k] = MyStrings[i][k + 1];
                MyStrings[i][L - 1] = temp1;
                count++;
            }
        }
        if (MyStrings[i] != MySwaps[index])
        {
            Found = false;
        }
        MyStrings[i] = TempVector[i];
    }
    if (count < min)
    {
        min = count;
    }
    StringReArrangements(Found, MyStrings, MySwaps, L, index + 1, count, min);
}

int main()
{
    int n;
    cin >> n;

    vector<string>arr;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        arr.push_back(s);
    }

    vector<string>Myswaps;
    int L = arr[0].length();
    for (int i = 0; i < L; i++)
    {
        Myswaps.push_back(arr[0]);
        char temp1 = arr[0][0];
        for (int k = 0; k < L - 1; k++)
            arr[0][k] = arr[0][k + 1];
        arr[0][L - 1] = temp1;
    }

    bool Found=true;

    int min = 999999;

    StringReArrangements(Found, arr, Myswaps, L, 0, 0, min);
    if (Found)
    {
        cout << min;
    }
    else
    {
        cout << -1;
    }




}