#include<bits/stdc++.h>
using namespace std;

// ! QUESTION



// ! SOLUTION


vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        vector<int> ans;
        
        int i= 0;
        int j= m-1;
        int diff = INT_MAX ;
        
        while(i<n && j>=0){
            int currDiff;
            currDiff =  abs(x - (arr[i]+brr[j]));
            if(currDiff < diff ){
                diff = currDiff;
                ans.clear();
                ans.push_back(arr[i]);
                ans.push_back(brr[j]);
            }
            if(arr[i]+brr[j]<x) i++;
            else if(arr[i]+brr[j]==0) break;
            else j--;
        }
       
        return ans;
    }