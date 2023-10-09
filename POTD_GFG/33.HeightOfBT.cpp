#include<bits/stdc++.h>
using namespace std;


// ! USING DFS

int height(struct Node* node){
        if(!node) return 0;
        
        return 1+max(height(node->right),height(node->left));
    } 


// ! USING BFS

int height(struct Node* node){
        queue<Node*>q;
        q.push(node);
        int ans = 0;
        while(!q.empty())
        {
            int size = q.size();
            ans++;
            
            while(size)
            {
                size--;
                Node* temp = q.front();
                q.pop();
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
        
        return ans;
    }