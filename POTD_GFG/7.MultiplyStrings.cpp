#include <bits/stdc++.h>
using namespace std;

// ! QUESTION
// Given two numbers as strings s1 and s2. Calculate their Product.

// Note: The numbers can be negative and You are not allowed to use any built-in function
// or convert the strings to integers. There can be zeros in the begining of the numbers.

// Example 1:

// Input:
// s1 = "0033"
// s2 = "2"
// Output:
// 66
// Example 2:

// Input:
// s1 = "11"
// s2 = "23"
// Output:
// 253

// * SOLUTION

string multiplyStrings(string s1, string s2)
{
    if (s1 == "0" || s2 == "0")
        return "0";

    int sign = 1;
    if (s1[0] == '-')
    {
        sign *= -1;
        s1 = s1.substr(1);
    }
    if (s2[0] == '-')
    {
        sign *= -1;
        s2 = s2.substr(1);
    }

    string ans(s1.length() + s2.length(), '0');

    for (int i = s2.length() - 1; i >= 0; i--)
    {
        int carry = 0;
        for (int j = s1.length() - 1; j >= 0; j--)
        {
            int product = (s1[j] - '0') * (s2[i] - '0') + (ans[i + j + 1] - '0') + carry;
            carry = product / 10;
            ans[i + j + 1] = (product % 10) + '0';
        }
        ans[i] += carry;
    }

    int start = 0;
    while (start < ans.length() - 1 && ans[start] == '0')
    {
        start++;
    }

    string result = ans.substr(start);
    if (sign == -1 && result != "0")
    {
        result = "-" + result;
    }

    return result;
}