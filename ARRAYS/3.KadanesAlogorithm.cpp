#include<bits/stdc++.h>
using namespace std;

// Given an array Arr[] of N integers. 
// Find the contiguous sub-array(containing at least one number) which has 
// the maximum sum and return its sum.


// Example 1:

// Input:
// N = 5
// Arr[] = {1,2,3,-2,5}
// Output:
// 9

 long long maxSubarraySum(int arr[], int n){
        
        
        long long maxSum=INT_MIN,currSum=0;
        
        for(int i=0;i<n;i++)
        {
            currSum+=arr[i];
            if(currSum>maxSum)
            {
                maxSum=currSum;
            }
            if(currSum<=0)
            {
                currSum=0;
            }
        }
        return maxSum;
    }
