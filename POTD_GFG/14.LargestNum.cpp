#include <bits/stdc++.h>
using namespace std;

// ! QUESTION

// Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits
// and whose sum of digits should be equals to 'S'. Return -1 if it is not possible.

// Example 1:

// Input: N = 2, S = 9
// Output: 90
// Explaination: It is the biggest number
// with sum of digits equals to 9.

// !  SOLUTION

string findLargest(int N, int S)
{

    if (S == 0 && N > 1 || N * 9 < S)  return "-1";

    string res = "";

    while (N > 0)
    {
        if (S >= 9)
        {
            res += '9';
            S -= 9;
        }
        else
        {
            res += '0' + S;
            S = 0;
        }
        N--;
    }

    return res;
}