#include<bits/stdc++.h>
#include "tree.h"
using namespace std;

// !   QUESTION

// Given the root of a binary tree, invert the tree, and return its root.
// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]

// ! SOLUTION

Node* helper(Node* root) {
        if(root == NULL)
            return NULL;

        if(root->left == NULL && root->right == NULL)
            return NULL;

        if(root->right == NULL) {
            root->right = root->left;
            root->left = NULL;
        }
        else if(root->left == NULL) {
            root->left = root->right;
            root->right = NULL;
        }


        else {
            Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        }

        helper(root->left);
        helper(root->right);

        return root;
        
    }

    Node* invertTree(Node* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return root;

        
        Node* temp = helper(root);

        return temp;
    }