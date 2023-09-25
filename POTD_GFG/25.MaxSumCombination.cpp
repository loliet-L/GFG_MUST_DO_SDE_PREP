#include<bits/stdc++.h>
using namespace std;

// !QUESTION

// Given two integer array A and B of size N each.
// A sum combination is made by adding one element from array A and another element of array B.
// Return the maximum K valid sum combinations from all the possible sum combinations.

// Note : Output array must be sorted in non-increasing order.

// Example 1:

// Input:
// N = 2
// K = 2
// A [ ] = {3, 2}
// B [ ] = {1, 4}
// Output: {7, 6}
// Explanation: 
// 7 -> (A : 3) + (B : 4)
// 6 -> (A : 2) + (B : 4)
// Example 2:

// Input:
// N = 4
// K = 3
// A [ ] = {1, 4, 2, 3}
// B [ ] = {2, 5, 1, 6}
// Output: {10, 9, 9}
// Explanation: 
// 10 -> (A : 4) + (B : 6)
// 9 -> (A : 4) + (B : 5)
// 9 -> (A : 3) + (B : 6)

// !SOLUTION


vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
         sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());

        vector<int> result;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int sum = A[i] + B[j];
                if (pq.size() < K)
                {
                    pq.push(sum);
                }
                else
                {
                    int currentMin = pq.top();
                    if (sum > currentMin)
                    {
                        pq.pop();
                        pq.push(sum);
                    }
                    else
                    {
                        break;
                    }
                }
            }   
        }
        
        while (!pq.empty())
        {
            auto val = pq.top();
            pq.pop();
            result.insert(result.begin(), val);
        }

        return result;
    }