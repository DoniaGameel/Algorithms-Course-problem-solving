#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    char c;
    int Value;
    vector<Node*>childs;
};

void DFS(Node* node,vector<int>&Stack)
{
    node->c='g';
    for(int j=0 ; j<node->childs.size();j++)
    {
        if(node->childs[j]->c=='w')
        {
            DFS(node->childs[j],Stack);
        }
    }
    node->c='b';
    Stack.push_back(node->Value);
}
int main() {
    int n;
    cin>>n;
    vector<Node*>arr;
    for(int i=0 ; i <n ; i++)
    {
        Node* nde=new Node;
        nde->Value=i;
        nde->c='w';
        arr.push_back(nde);
    }
    for(int i=0 ; i <n ; i++)
        for(int j=0 ; j<2 ; j++)
        {
            int x;
            cin>>x;
            if(x!=-1)
            {
                arr[x]->childs.push_back(arr[i]);
            }
        }
    
    vector<int>Stack;
    for(int i=0;i<n;i++)
    {
        if(arr[i]->c=='w')
        {
            DFS(arr[i],Stack);
        }
    }
    while(Stack.size()!=0)
    {
        cout << Stack.back() << " ";
        Stack.pop_back();
    }
    return 0;
}
