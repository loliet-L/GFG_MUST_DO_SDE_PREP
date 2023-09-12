#include <bits/stdc++.h>
using namespace std;


// ! QUESTION

// Given a number N, check if a number is perfect or not. 
// A number is said to be perfect if sum of all its factors excluding the number itself 
// is equal to the number. Return 1 if the number is Perfect otherwise return 0.

// Example 1:

// Input:
// N = 6
// Output:
// 1 
// Explanation:
// Factors of 6 are 1, 2, 3 and 6.
// Excluding 6 their sum is 6 which
// is equal to N itself. So, it's a
// Perfect Number.


// ! SOLUTION

int isPerfectNumber(long long N) {
        if(N==1)return 0;
        long long sum=1;
        int i=2;
        while(i<=sqrt(N))
        {
            if(N%i==0)
            {
                sum+=i;
                if(i!=N/i) sum+=(N/i);
            }
            i++;
        }
        
        if (sum==N) return 1;
        return 0;
    }