#include<bits/stdc++.h>
#include "tree.h"
using namespace std;

// ! QUESTION 

// Given a BST and a key K. If K is not present in the BST, 
// Insert a new Node with a value equal to K into the BST. If K is already present in the BST, don't modify the BST.

// Example 1:

// Input:
//      2
//    /   \   1     3
// K = 4
// Output: 
// 1 2 3 4
// Explanation: 
// After inserting the node 4
// Inorder traversal will be 1 2 3 4.


// ! SOLUTION

        Node* insert(Node* node, int data) {
        
            if(node==NULL) return newNode(data);
            else if(data > node->data){
                node->right = insert(node->right,data);
            }else if(data < node->data){
                node->left = insert(node->left,data);
            }
        
        return node;
    }