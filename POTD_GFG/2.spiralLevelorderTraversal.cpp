#include<bits/stdc++.h>
#include "tree.h"
using namespace std;

// Given a binary tree and the task is to find the spiral order traversal of the tree.

// Spiral order Traversal mean: Starting from level 0 for root node, 
// for all the even levels we print the node's value from right to left and 
// for all the odd levels we print the node's value from left to right. 

// For below tree, function should return 1, 2, 3, 4, 5, 6, 7.


// * USING QUEUE

vector<int> findSpiral(Node *root)
{
    vector<int>res;
    if(!root) return res;
    
    queue<Node*>q;
    q.push(root);
    bool s = false;
    
    while(!q.empty())
    {
        int n=q.size();
        
        vector<int>v;
        
        
        for(int i=0;i<n;i++)
        {
            Node* temp =q.front();
            q.pop();
            v.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        
        if(s==false)
        {
            res.insert(res.end(),v.rbegin(),v.rend());
            s=true;
        }
        else 
        {
            res.insert(res.end(),v.begin(),v.end());
            s=false;
        }
    }
    
    return res;
}


// * USING DEQUEUE


vector<int> findSpiral(Node *root)
{
   //Your code here
    deque<Node*> q;
    vector<int> ans;
    bool flag = true;
    q.push_front(root);
    
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            if (flag) {
                Node *node = q.front();
                q.pop_front();
                ans.push_back(node->data);
                if (node->right) q.push_back(node->right);
                if (node-> left) q.push_back(node->left);
            }
            else {
                Node *node = q.back();
                q.pop_back();
                ans.push_back(node->data);
                if (node->left) q.push_front(node->left);
                if (node->right) q.push_front(node->right);
            }
        }
        sz = q.size();
        flag = !flag;
    }
    
    return ans;
}