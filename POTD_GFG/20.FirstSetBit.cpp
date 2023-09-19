#include <bits/stdc++.h>
using namespace std;


// ! QUESTION

// Given an integer N. The task is to return the position of first set bit found from the right side 
// in the binary representation of the number.
// Note: If there is no set bit in the integer N, then return 0 from the function.  

// Example 1:

// Input: 
// N = 18
// Output: 
// 2
// Explanation: 
// Binary representation of 18 is 010010,the first set bit from the right side is at position 2.

// ! SOLUTION


unsigned int getFirstSetBit(int n)
    {
         int count = 1;
    while (n > 0 && (n & 1) == 0) {
        n >>= 1;
        count++;
    }
    return n > 0 ? count : 0;
    }