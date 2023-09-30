#include <bits/stdc++.h>
using namespace std;

// ! QUESTION

// Given an integer array nums, return an array answer such that answer[i] is equal to
// the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

// ! SOLUTION

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    int fromBegin = 1;
    int fromLast = 1;
    vector<int> res(n, 1);

    for (int i = 0; i < n; i++)
    {
        res[i] *= fromBegin;
        fromBegin *= nums[i];
        res[n - 1 - i] *= fromLast;
        fromLast *= nums[n - 1 - i];
    }
    return res;
}