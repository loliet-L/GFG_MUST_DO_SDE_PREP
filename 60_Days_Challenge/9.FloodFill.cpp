#include<bits/stdc++.h>
using namespace std;


// ! QUESTION

// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
// You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the
//  same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. 
// Replace the color of all of the aforementioned pixels with color.
// Return the modified image after performing the flood fill.

// ! SOLUTION


// * USING BFS 

    vector<vector<int>> floodFill(vector<vector<int>> &image,int sr,int sc,int color){
        if(color==image[sr][sc]){
            return image;
        }
        int original=image[sr][sc];
        int m=image.size(),n=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                pair<int,int> current=q.front();
                q.pop();
                int currX=current.first,currY=current.second;
                image[currX][currY]=color;
                vector<int> dx={-1,0,1,0};
                vector<int> dy={0,-1,0,1};
                for(int i=0;i<4;i++){
                    int x=currX+dx[i],y=currY+dy[i];
                    if(x>=0 && x<m && y>=0 && y<n && image[x][y]==original){
                        q.push({x,y});
                    }
                }
            }
        }
        return image;
    }