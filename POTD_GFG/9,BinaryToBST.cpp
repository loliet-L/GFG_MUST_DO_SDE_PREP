#include<bits/stdc++.h>
using namespace std;

// ! Question

// Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
//  Example 1:

// Input:
//       1
//     /   \
//    2     3
// Output: 
// 1 2 3
// Explanation:
// The converted BST will be 
//       2
//     /   \
//    1     3


// ! SOLUTION


 void traverse(Node* root, priority_queue<int>& pq){
        if(!root) return;
        
        pq.push(root->data);
        traverse(root->left, pq);
        traverse(root->right, pq);
    } 
    void putElements(Node* root, priority_queue<int>& pq){
        if(!root)
            return;
        
        putElements(root->right, pq);        // Right Subtree
        root->data = pq.top();             // Assigning Values
        pq.pop();
        putElements(root->left, pq);         // Left Subtree
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        priority_queue<int>pq;
        traverse(root, pq);       // Preorder traversal to store the elements in sorted order
        putElements(root, pq);    // Perform Inorder traversal to assign correct values
        
        return root;
    }
