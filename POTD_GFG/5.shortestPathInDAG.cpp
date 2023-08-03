#include "bits/stdc++.h"
using namespace std;

// Given a Directed Acyclic Graph of N vertices from 0 to N-1 and 
// a 2D Integer array(or vector) edges[ ][ ] of length M, 
// where there is a directed edge from edge[i][0] to edge[i][1] 
// with a distance of edge[i][2] for all i.

// Find the shortest path from src(0) vertex to all the vertices 
// and if it is impossible to reach any vertex, then return -1 for that vertex.

// Example1:

// Input:
// N = 4, M = 2
// edge = [[0,1,2],[0,2,1]
// Output:
// 0 2 1 -1
// Explanation:
// Shortest path from 0 to 1 is 0->1 with edge weight 2. 
// Shortest path from 0 to 2 is 0->2 with edge weight 1.
// There is no way we can reach 3, so it's -1 for 3.


 vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         
          vector<int>dist(N,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>,  greater<pair<int,int>>>pq;
        
        dist[0]=0;
        
        vector<vector<int>> adj[N];
        
        for(auto e : edges){
            adj[e[0]].push_back( {e[1], e[2]} );
        }
        
        
        pq.push({dist[0],0});  //{dist[node],node} , here src/node=0;
        
        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();
            
            int node=front.second;
            int dis=front.first;
            
            for(auto it:adj[node]){
                int weightNode=it[1];
                int adjNode=it[0];
                
                if(dis+weightNode<dist[adjNode]){
                    dist[adjNode]=dis+weightNode;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        for(auto &a : dist)
            if(a==INT_MAX)a = -1;
       
        
        return dist;
    }