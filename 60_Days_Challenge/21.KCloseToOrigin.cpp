#include<bits/stdc++.h>
using namespace std;

// !  QUESTION

// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, 
// return the k closest points to the origin (0, 0).
// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

// Example 1:

// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
// Example 2:

// Input: points = [[3,3],[5,-1],[-2,4]], k = 2
// Output: [[3,3],[-2,4]]
// Explanation: The answer [[-2,4],[3,3]] would also be accepted.



// ! Intuition :-

// The intuition we all got at first was to sort the points in increasing order and just do the math. 
// But this is not a viable solution, i believe this the worst solution beacause let's think of a scenerio
// were there will be streaming of online data.Everytime a new data[points] comes, we need to sort the entire inputs 
// till that point and since it's online we all know how much data could have been there in just one sec .
// So a good solution can be a heap approach. To be specific a maxheap since in minheap It will store all 
// the array elements and this can be costly for large elemented arrays while in maxheap we just need to store k elements.
// ALWAYS REMEMBER :-Whenever a question asks for k closest or k smallest or k largest it's a heap question .
// Though these questions might be implemented using other algorithms as well but heap will allow to simplify the problem 
// as well as code and your code will have a achievement unlocked known as erorr resistnace , lol.

// ! SOLUTION


 vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         //Answer vector
        vector<vector<int>> result(k);
        //maxheap storage initialization
        priority_queue<vector<int>> maxHeap;
        //Construction of maxheap
        for (auto& p : points) {
            int x = p[0], y = p[1];
            maxHeap.push({x*x + y*y, x, y});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        for (int i = 0; i < k; ++i) {
            vector<int> top = maxHeap.top();
            maxHeap.pop();
            result[i] = {top[1], top[2]};
        }
        
        return result;
    }