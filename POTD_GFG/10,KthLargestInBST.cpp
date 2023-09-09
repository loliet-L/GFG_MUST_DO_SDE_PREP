#include<bits/stdc++.h>
#include  "tree.h"
using namespace std;

//  ! QUESTION
// Given a Binary Search Tree. 
// Your task is to complete the function which will return the Kth largest element 
// without doing any modification in Binary Search Tree.

// Example 1:

// Input:
//       4
//     /   \
//    2     9
// k = 2 
// Output: 4

// ! SOLUTION


void reverse_inorder(Node* root,int &k,int &res)
    {
        if(!root)return;
        
        reverse_inorder(root->right,k,res);
        k--;
        
        if(k==0){
            res=root->data;
            return;
        }
        reverse_inorder(root->left,k,res);
    }
    int kthLargest(Node *root, int k)
    {
       int res=-1;
       reverse_inorder(root,k,res);
       return res;
    }