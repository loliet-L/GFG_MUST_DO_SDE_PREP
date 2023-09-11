#include<bits/stdc++.h>
#include "tree.h"
using namespace std;

// ! QUESTION

// Given a binary tree, determine if it is 
// height-balanced

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: true


// !  SOLUTION

 bool isBalanced(Node* root) {
        // If the tree is empty, we can say it’s balanced...
        if (!root)  return true;
        // Height Function will return -1, when it’s an unbalanced tree...
		if (Height(root) == -1)  return false;
		return true;
	}
    // Create a function to return the “height” of a current subtree using recursion...
	 int Height(Node* root) {
        // Base case...
		if (!root)  return 0;
        // Height of left subtree...
		int leftHeight = Height(root->left);
        // Height of height subtree...
		int rightHight = Height(root->right);
        // In case of left subtree or right subtree unbalanced, return -1...
		if (leftHeight == -1 || rightHight == -1)  return -1;
        // If their heights differ by more than ‘1’, return -1...
        if (abs(leftHeight - rightHight) > 1)  return -1;
        // Otherwise, return the height of this subtree as max(leftHeight, rightHight) + 1...
		return max(leftHeight, rightHight) + 1;
    }