#include<bits/stdc++.h>
using namespace std;

// !    QUESTION


// Given a sorted array arr containing n elements with possibly duplicate is to find indexes of first elements, 
// the task is to find the first and last occurrences of an element x in the given array.
// Note: If the number x is not found in the array then return both the indices as -1.


// Example 1:

// Input:
// n=9, x=5
// arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
// Output:  
// 2 5
// Explanation: 
// First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 
// Example 2:

// Input:
// n=9, x=7
// arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
// Output:  
// 6 6
// Explanation: 
// First and last occurrence of 7 is at index 6.


// ! SOLUTION

vector<int> find(int arr[], int n , int x )
    {
        int low=0,high=n-1;
        int first=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==x){
                first=mid;
                high=mid-1;
            }
            if(arr[mid]>x) high=mid-1;
            if(arr[mid]<x) low=mid+1;
          
        }
        low=0,high=n-1;
        int last=-1;
          while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==x){
                last=mid;
                low=mid+1;
            }
            if(arr[mid]>x) high=mid-1;
            if(arr[mid]<x) low=mid+1;
           
        }
     return {first,last};
        
    }