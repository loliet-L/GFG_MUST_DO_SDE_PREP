#include<bits/stdc++.h>
using namespace std;

// ! QUESTION
// Given a string you need to print the size of the longest possible substring that has exactly 
// K unique characters. If there is no possible substring then print -1.

// Example 1:

// Input:
// S = "aabacbebebe", K = 3
// Output: 
// 7
// Explanation: 
// "cbebebe" is the longest substring with 3 distinct characters.

// !SOLUTION


// *approach ( using sliding window and hashmap  )

int longestKSubstr(string s, int k) {
        int i=0,j=0,n=s.size(),maxi=-1;
        unordered_map<char,int>m;
        while(j<n){
            m[s[j]]++;
            while(m.size()>k){
                m[s[i]]--;
                if(m[s[i]]==0){
                    m.erase(s[i]);
                }
                i++;
            }
            if(m.size()==k)
                maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
        
    }