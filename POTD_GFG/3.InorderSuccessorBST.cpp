#include<bits/stdc++.h>
#include "tree.h"
using namespace std;

Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node*ans = NULL;
        
        while(root != NULL)
        {
           if(root->data <= x->data)
           {
               root = root->right;
           }
           else
           {
               ans = root;
               root = root->left;
           }
        }
        return ans; 
    }