#include<bits/stdc++.h>
using namespace std;


// !   QUESTION

// Given an array A of n positive numbers. The task is to find the first equilibrium point in an array. 
// Equilibrium point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
// Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists. 

// Example 1:

// Input: 
// n = 5 
// A[] = {1,3,5,2,2} 
// Output: 
// 3 
// Explanation:  
// equilibrium point is at position 3 as sum of elements before it (1+3) = sum of elements after it (2+2). 
// Example 2:

// Input:
// n = 1
// A[] = {1}
// Output: 
// 1
// Explanation:
// Since there's only element hence its only the equilibrium point.

// ! SOLUTION

int equilibriumPoint(long long a[], int n) {
    
       if(n==1) return 1;
       int preSum[n] ={0};
       int afterSum[n]={0};
       preSum[0]=a[0];
       afterSum[0]=a[n-1];
       
       for(int i=1;i<n;i++)
       {
           preSum[i]+=a[i]+preSum[i-1];
           afterSum[i]=a[n-1-i]+afterSum[i-1];
       }
       
       int i=0;
       
       while(preSum[i]!=afterSum[n-i-1] && i<n)
       {
           
           i++;
       }
       
       if( i==n) return -1;
       return i+1;
    }