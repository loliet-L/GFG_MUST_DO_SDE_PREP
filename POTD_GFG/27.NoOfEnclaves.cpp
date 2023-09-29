#include<bits/stdc++.h>
using namespace std;

// ! QUESTION

// You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

// Example 1:

// Input:
// grid[][] = {{0, 0, 0, 0},
//             {1, 0, 1, 0},
//             {0, 1, 1, 0},
//             {0, 0, 0, 0}}
// Output:
// 3
// Explanation:
// 0 0 0 0
// 1 0 1 0
// 0 1 1 0
// 0 0 0 0
// The highlighted cells represents the land cells.
// Example 2:

// Input:
// grid[][] = {{0, 0, 0, 1},
//             {0, 1, 1, 0},
//             {0, 1, 1, 0},
//             {0, 0, 0, 1},
//             {0, 1, 1, 0}}
// Output:
// 4
// Explanation:
// 0 0 0 1
// 0 1 1 0
// 0 1 1 0
// 0 0 0 1
// 0 1 1 0
// The highlighted cells represents the land cells.

// ! SOLUTION

void dfs(vector<vector<int>> &g,int r, int c,int n,int m)
    {
        g[r][c]=0;
        vector<int> row={0,1,0,-1};
        vector<int> col={1,0,-1,0};
        for(int i=0;i<4;i++)
        {
            int nR=r+row[i];
            int nC=c+col[i];
            
            if(nR>=0 && nC>=0 && nR<n && nC<m  && g[nR][nC]==1)
            {
                dfs(g,nR,nC,n,m);
            }
        }
    }

    int numberOfEnclaves(vector<vector<int>> &grid) {
         int n=grid.size();
         int m=grid[0].size();
         
        //  for checking first and last row
        
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1)
            {
                dfs(grid,0,i,n,m);
            }
            
            if(grid[n-1][i]==1)
            {
                dfs(grid,n-1,i,n,m);
            }
        }
        
        //  for checking first and last column
        
        for(int i=1;i<n-1;i++)
        {
            if(grid[i][0]==1)
            {
                dfs(grid,i,0,n,m);
            }
            
            if(grid[i][m-1]==1)
            {
                dfs(grid,i,m-1,n,m);
            }
        }
        
        int res=0;
        
        
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(grid[i][j]==1)res++;
            }
        }
        
        return res;
    }