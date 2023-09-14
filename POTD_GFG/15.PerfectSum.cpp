#include<bits/stdc++.h>
using namespace std;


// !QUESTION

// Given an array arr[] of non-negative integers and an integer sum, 
// the task is to count all subsets of the given array with a sum equal to a given sum.

// Note: Answer can be very large, so, output answer modulo 109+7

// Example 1:

// Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
//        sum = 10
// Output: 3
// Explanation: {2, 3, 5}, {2, 8}, {10} are 
// possible subsets.
// Example 2:
// Input: N = 5, arr[] = {1, 2, 3, 4, 5}
//        sum = 10
// Output: 3
// Explanation: {1, 2, 3, 4}, {1, 4, 5}, 
// {2, 3, 5} are possible subsets.

// ! SOLUTION

const int mod=1e9+7;
	
	int solve(int i, int arr[], int sum, vector<vector<int>>&dp){
	    if (i < 0) {
            if (sum == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        
        if(dp[i][sum]!=-1) return dp[i][sum];
	    
	    int take=0;
	    if(sum>=arr[i]){
	        take=solve(i-1, arr, sum-arr[i], dp);
	    }
	    int ntake=solve(i-1, arr, sum, dp);
	    return dp[i][sum]=(take+ntake)%mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return solve(n-1, arr, sum, dp);
	}