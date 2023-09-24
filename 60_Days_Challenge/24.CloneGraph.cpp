#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


// !    QUESTION

// Given a reference of a node in a connected undirected graph.

// Return a deep copy (clone) of the graph.

// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

// class Node {
//     public int val;
//     public List<Node> neighbors;
// }
 

// Test case format:

// For simplicity, each node's value is the same as the node's index (1-indexed). 
// For example, the first node with val == 1, the second node with val == 2, and so on. 
// The graph is represented in the test case using an adjacency list.
// An adjacency list is a collection of unordered lists used to represent a finite graph. 
// Each list describes the set of neighbors of a node in the graph.
// The given node will always be the first node with val = 1. 
// You must return the copy of the given node as a reference to the cloned graph.

// ! SOLUTION



unordered_map<Node* , Node*> mp; // declaring map, to check whwther we have a copy of node or not and also to store copy
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) // if node is null, then simply return null
        {
            return NULL;
        }
        
        Node* first = new Node(node -> val, {}); // make a copy of first node
        mp[node] = first;
        
        queue<Node*> q; //For bfs, we create queue
        q.push(node); // push into queue
        
        while(q.empty() == false) // until q. empty == false
        {
            Node* curr = q.front(); // extract front node
            q.pop(); // pop that from queue
            
            for(auto adj: curr -> neighbors) // now travel in adjcant
            {
                if(mp.find(adj) == mp.end()) // if not present in map
                {
                    mp[adj] = new Node(adj -> val, {}); // then create copy
                    q.push(adj); // push nto the queue
                    
                }
                
                mp[curr] -> neighbors.push_back(mp[adj]); // in current node push adjcant node
            }
        }
        
        return mp[node];
    }