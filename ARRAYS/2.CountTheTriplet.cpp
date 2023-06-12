
#include<bits/stdc++.h>
using namespace std;


// Given an array of distinct integers. 
// The task is to count all the triplets such that sum of two elements equals the third element.
 
// Example 1:

// Input: 
// N = 4 
// arr[] = {1, 5, 3, 2}
// Output: 2 
// Explanation: There are 2 triplets:
//  1 + 2 = 3 and 3 +2 = 5


//  * without sorting 

int countTriplet(int arr[], int n)
	{
	       unordered_map<int,int>ump1;
        for(int i=0;i<n;i++)
        {
            ump1[arr[i]]++;
        }
        
        int count = 0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int sum = arr[i]+arr[j];
                if(ump1[sum])
                {
                    count++;
                }
            }
        }
        
        return count;
	}

    //  * with sorting ( using 2 pointer approach) 


	int countTriplet(int arr[], int n)
	{
	      sort(arr, arr+n);
	      
	      int res=0;
	      
	      for (int i=0;i<n; i++)
	      {
	          int j =0;
	          int k=i-1;
	          
	          while(j<k)
	          {
	              if(arr[i] == arr[j] + arr[k] ){
	                  res++,j++,k--;
	              }
	               else if  (arr[i] < arr[j] + arr[k]) {
	                   k--;
	               }
	               else j++;
	          }
	      }
	      
	      return res;
	}
