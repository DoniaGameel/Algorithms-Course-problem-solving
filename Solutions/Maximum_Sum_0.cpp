#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// This code is used for guidance (you can change it if you want).

struct Node
{
  int index;
  int rating;
  Node* parent; // this is optional
  vector<Node*> children;
};


long long maximumSum(Node* root, vector<long long>&memo) {
  
  if(root==nullptr)
      return  0;
    long long Sum1=0;
    long long Sum2=root->rating;
  for(int i=0 ; i<root->children.size();i++)
  {
      if(memo[root->children[i]->index]<0)
      {
          memo[root->children[i]->index]= maximumSum( root->children[i],memo );
          Sum1+=memo[root->children[i]->index];
      }
      else   
            Sum1+=memo[root->children[i]->index];
  }
  for(int i=0 ; i<root->children.size();i++)
  {
      for(int j = 0 ; j<root->children[i]->children.size();j++)
      {
          if(memo[root->children[i]->children[j]->index]<0)
      {
          memo[root->children[i]->children[j]->index]= maximumSum( root->children[i]->children[j],memo );
          Sum2+=memo[root->children[i]->children[j]->index];
      }
      else   
            Sum2+=memo[root->children[i]->children[j]->index];
      }
  }
 if(Sum1>Sum2)
     return memo[root->index]= Sum1;
   return memo[root->index]=Sum2; 
}


int main() {

  // Number of nodes in the tree
  int N;
  cin >> N;

  vector<Node*> nodes(N);
  for (int i = 0; i < N; i++) {
    nodes[i] = new Node;
    nodes[i]->index = i;
    cin >> nodes[i]->rating;
  }

  // Iterating over all edges
  int parent, child;
  for (int i = 0; i < N-1; i++) {
    cin >> parent >> child;
    nodes[child]->parent = nodes[parent];
    nodes[parent]->children.push_back(nodes[child]);
  }
  
  vector<long long>memo(N,-1) ;
   cout << maximumSum(nodes[0], memo);

  return 0;
}