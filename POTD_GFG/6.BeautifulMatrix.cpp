#include<bits/stdc++.h>
using namespace std;


// ! QUESTION
// A beautiful matrix is a matrix in which the sum of elements in each row and column is equal. 
// Given a square matrix of size NxN. Find the minimum number of operation(s) that are required 
// to make the matrix beautiful. In one operation you can increment the value of any one cell by 1.
// Example 1:

// Input:
// N = 2
// matrix[][] = {{1, 2},
//               {3, 4}}
// Output: 
// 4
// Explanation:
// Updated matrix:
// 4 3
// 3 4
// 1. Increment value of cell(0, 0) by 3
// 2. Increment value of cell(0, 1) by 1
// Hence total 4 operation are required.


//? APPROACH
// ! 1 STORE PREFIX SUM OF ROWS AND COL IN ROWSUM AND COLSUM ARRAYS
//!  2 AND FIND THE MAXSUM WHILE DOING SO
// ! 3 ITERATION OVER THE MATRIX AND FIND THE DIFFERENCE BTWN THE MAX(ROWSUM,COLSUM) AND ,MAXSUM
// !   ADD IT TO THE RESULT
// ! 4 UPDATE THE ROWSUM AND COLSUM




// * SOLUTION


int findMinOpeartion(vector<vector<int> > mat, int n)
    {
        vector<int> rowSum(n,0);
        vector<int>colSum(n,0);
        int maxSum=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int row=0,col=0;
            for(int j=0;j<n;j++)
            {
                row+=mat[i][j];
                col+=mat[j][i];
            }
            rowSum[i]=row;
            colSum[i]=col;
            maxSum=max(maxSum,max(row,col));
        }
        
        
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int sum=max(rowSum[i],colSum[j]);
                int difference = maxSum-sum;
                
                res+=difference;
                rowSum[i]+=difference;
                colSum[j]+=difference;
            }
        }
        
         return res;
    } 