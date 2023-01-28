#include<iostream>
using namespace std;
#include<string>

void StringDifferences(int N, int H, string s)
{
    if (s.size() == N)
    {
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            if (s[i] == '1')
                count++;
        }
        if (count == H)
            cout << s << endl;
        return;
    }
    StringDifferences(N, H, s + "0");
    StringDifferences(N, H, s + "1");
}

int main()
{
    int H;
    int N;
    cin >> N >> H;
    StringDifferences(N, H, "");
    return 0;
}
