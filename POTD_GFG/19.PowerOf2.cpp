#include <bits/stdc++.h>
using namespace std;


// ! QUESTION

// Given a non-negative integer N. The task is to check if N is a power of 2. 
// More formally, check if N can be expressed as 2x for some integer x.

// Example 1:

// Input: 
// N = 8
// Output: 
// YES
// Explanation:
// 8 is equal to 2 raised to 3 (23 = 8).

// ! SOLUTION

 bool isPowerofTwo(long long n){
        if(n==0) return false;
        
        if ( ( n & (n-1))==0 ) return true;
        
        return false;
    
        
    }