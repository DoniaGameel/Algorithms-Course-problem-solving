#include <iostream>
using namespace std;
#include <vector>
#include"algorithm"
#include <unordered_map>
#include<numeric>
#include<string>
struct Node
{
    int index;
    int value;
    int level;
    Node* left = nullptr;
    Node* right = nullptr;
};

void GetLevel(Node* node)
{
    if ((node) == nullptr)
        return;
    if (node->left != nullptr)
        node->left->level = (node->level) + 1;
    if (node->right != nullptr)
        node->right->level = (node->level) + 1;
    GetLevel(node->left);
    GetLevel(node->right);

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<Node*> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = new Node;
        int x;
        cin >> x;
        arr[i]->value = x;
        arr[i]->index = i;
    }

    int E;
    cin >> E;
    for (int i = 0; i < E; i++)
    {
        char c;
        int p;
        int Child;
        cin >> c;
        cin >> p;
        cin >> Child;
        if (Child >= 0 && Child < n && p >= 0 && p < n)
        {
            if (c == 'L')
                arr[p]->left = arr[Child];
            if (c == 'R')
                arr[p]->right = arr[Child];
        }

    }
    arr[0]->level = 0;
    GetLevel(arr[0]);
    unordered_map<int, vector <int>> U;
    for (int i = 0; i < n; i++)
    {
        auto it = U.find(arr[i]->level);
        if (it != U.end())
            U[arr[i]->level].push_back(arr[i]->value);
        else
        {
            vector <int>v;
            v.push_back(arr[i]->value);
            U.insert({ arr[i]->level , v });
        }
    }

    int MaxLevel = 0;
    for (auto it = U.begin(); it != U.end(); it++)
    {
        if ((it->first) > MaxLevel)
            MaxLevel = it->first;
    }
    int NoOfLevels = MaxLevel + 1;
    int L = (arr[0]->value) % NoOfLevels;
    int k = (*min_element(U[L].begin(), U[L].end())) % NoOfLevels;
    if (k == 0)
    {
        k = 1;
    }

    vector<int>SumVector;
    string s="";
    for (int i = 0; i < NoOfLevels; i++)
    {
        if (i % k == 0)
        {
            int sum = accumulate(U[i].begin(), U[i].end(), 0);
            s+=to_string(sum);
          
        }
    }
    cout << s;
    return 0;
}
