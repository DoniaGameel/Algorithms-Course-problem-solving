#include <iostream>
using namespace std;
#include <vector>
struct Node2
{
    int id;
    Node2* left;
    Node2* right;
    Node2* parent;

};

struct Node1
{
    int key;
    Node1* left;
    Node1* right;
    Node1* parent;
    Node2* ptr12;
};
void InsrtionTreeTwo(Node2*& T2, int IDToInsert)
{
    Node2* z = new Node2;
    z->id = IDToInsert;
    z->left = nullptr;
    z->right = nullptr;
    z->parent = nullptr;

    Node2* x = T2;
    Node2* y = nullptr;
    while (x != nullptr)
    {
        y = x;
        if (z->id < x->id)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == nullptr)
    {
        T2 = z;
    }
        
    else if ((z->id) < (y->id))
    {
        y->left = z;
        
    }
       
    else if ((z->id) > (y->id))
        y->right = z;

}

void InsrtionTreeOne(Node1*& T1, int keyToInsert, int idToInsert)
{
    
    Node1* z = new Node1;
    z->key = keyToInsert;
    z->left = nullptr;
    z->right = nullptr;
    z->parent = nullptr;
    z->ptr12 = nullptr;
    Node1* x = T1;
    Node1* y = nullptr;
    while (x != nullptr)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else if (z->key > x->key)
            x = x->right;
        else
            break;
    }
    z->parent = y;
    if (y == nullptr)
    {
        T1 = z;
        Node2* T2 = nullptr;
        InsrtionTreeTwo(T2, idToInsert);
        T1->ptr12 = T2;
    }
    else if ((z->key) < (y->key))
    {
        y->left = z;
        Node2* T2 = nullptr;
        InsrtionTreeTwo(T2, idToInsert);
        z->ptr12 = T2;
    }
    else if ((z->key) > (y->key))
    {
        y->right = z;
        Node2* T2 = nullptr;
        InsrtionTreeTwo(T2, idToInsert);
        z->ptr12 = T2;
    }
    else if ((z->key) == (y->key))
    {
        InsrtionTreeTwo(y->ptr12, idToInsert);
    }


}
void SearchTreeTwo(Node2* Tree2, int IDToSearch, bool& b, int& x)
{
    
    Node2* node2ptr = Tree2;
    if (node2ptr == nullptr)
        cout << x << " " << b << endl;
    else
    {
        x++;
        if (node2ptr->id == IDToSearch)
        {
            b = 1;
            cout << x << " " << b << endl;
        }
        else if (node2ptr->id < IDToSearch)
        {
            return SearchTreeTwo(node2ptr->right, IDToSearch, b, x);
        }
        else
        {
            return SearchTreeTwo(node2ptr->left, IDToSearch, b, x);
        }
    }
}
void SearchTreeOne(Node1* node1ptr, int keyToSearch, int IDToSearch, int& x)
{
    bool b = 0;
    if (node1ptr == nullptr)
        cout << x << " " << b << endl;
    else
    {
        x++;
        if (node1ptr->key == keyToSearch)
        {
            Node2* node2ptr = node1ptr->ptr12;
            SearchTreeTwo(node2ptr, IDToSearch, b, x);
        }
        else if (node1ptr->key < keyToSearch)
        {
            return SearchTreeOne(node1ptr->right, keyToSearch, IDToSearch, x);
        }
        else
        {
            return SearchTreeOne(node1ptr->left, keyToSearch, IDToSearch, x);
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Node1* tree1 = nullptr;
    int N;
    cin >> N;
    int Q;
    cin >> Q;
    for (int i = 0; i < N; i++)
    {
        int key;
        int id;
        cin >> key;
        cin >> id;
        InsrtionTreeOne(tree1, key, id);
    }
    vector<pair<int, int>>MyVec;
    for (int i = 0; i < Q; i++)
    {
        int key;
        int id;
        cin >> key;
        cin >> id;
        MyVec.push_back({ key,id });

    }
    for (int i = 0; i < Q; i++)
    {
        int x = 0;
        SearchTreeOne(tree1, MyVec[i].first, MyVec[i].second, x);
    }
}