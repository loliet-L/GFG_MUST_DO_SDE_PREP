#include <bits/stdc++.h>
using namespace std;

// ! QUESTION

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3



// ! SOLUTION


void dfs(vector<vector<char>>& grid,int i,int j)
    {
        if(i>=grid.size() || j>= grid[0].size()|| j<0 || i<0 || grid[i][j] == '0')
            return ;
        grid[i][j] = '0';
        dfs(grid,i+1,j);   
        dfs(grid,i,j+1);  
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        // dfs(grid,i-1,j+1);  
        // dfs(grid,i-1,j-1);
        // dfs(grid,i+1,j+1);  
        // dfs(grid,i+1,j-1);  
    }
    
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i =0 ;i<grid.size(); i++)
            for(int j =0; j<grid[0].size(); j++)
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    ans++;
                }
        return ans;
    }