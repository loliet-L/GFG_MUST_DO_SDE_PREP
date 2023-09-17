#include <bits/stdc++.h>
using namespace std;


// ! QUESTION

// Given a number N, find the first N Fibonacci numbers. The first two number of the series are 1 and 1.

// Example 1:

// Input:
// N = 5
// Output: 1 1 2 3 5
// Example 2:

// Input:
// N = 7
// Output: 1 1 2 3 5 8 13

// ! SOLUTION

vector<long long> printFibb(int n) 
    {
        vector<long long> dp(n);
        dp[0]=1;
        dp[1]=1;
        int i=2;
        
        while(i<n)
        {
            dp[i]=dp[i-1]+dp[i-2];
            i++;
        }
        return dp;
    }