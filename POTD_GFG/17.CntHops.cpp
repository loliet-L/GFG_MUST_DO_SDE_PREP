#include<bits/stdc++.h>
using namespace std;


// !QUESTION

// A frog jumps either 1, 2, or 3 steps to go to the top. 
// In how many ways can it reach the top of Nth step. 
// As the answer will be large find the answer modulo 1000000007.

// Example 1:

// Input:
// N = 1
// Output: 1
// Example 2:

// Input:
// N = 4
// Output: 7
// Explanation:Below are the 7 ways to reach
// 4
// 1 step + 1 step + 1 step + 1 step
// 1 step + 2 step + 1 step
// 2 step + 1 step + 1 step
// 1 step + 1 step + 2 step
// 2 step + 2 step
// 3 step + 1 step
// 1 step + 3 step

// ! SOLUTION

int long long mod = 1e9 + 7;
    long long countWays(int n)
    {
     long long int *arr = new long long int[n + 1];
       arr[0] = 1;
       arr[1] = 1;
       arr[2] = 2;
       for (int i = 3; i <= n; i++) {
      arr[i] = arr[i - 1] % mod + arr[i - 2] % mod + arr[i - 3] % mod;
     }
     return arr[n] % mod;
    }