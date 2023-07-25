#include<bits/stdc++.h>
#include "tree.h"
using namespace std;



// Given a Binary Tree, find Right view of it. Right view of a Binary Tree
//  is set of nodes visible when tree is viewed from right side.

// Right view of following tree is 1 3 7 8.

//           1
//        /      \
//      2         3
//    /   \      /  \
//   4     5   6    7
//    \
//      8

 vector<int> rightView(Node *root)
    {
      vector<int> res;
       if(!root) return res;
       
       queue<Node*>q;
       q.push(root);
       
       while(!q.empty())
       {
           int size=q.size();
           
           for(int i=0;i<size;i++)
           {
               Node* node =q.front();
               q.pop();
               if(i==size-1)res.push_back(node->data);
               
               if(node->left)q.push(node->left);
               if(node->right) q.push(node->right);
           }
       }
       
       return res;
    }
