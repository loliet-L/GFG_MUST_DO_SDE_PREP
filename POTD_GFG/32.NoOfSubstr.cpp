#include<bits/stdc++.h>
using namespace std;

// ! QUESTION

// Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that have 
// exactly k distinct characters. 

// Example 1:

// Input:
// S = "aba", K = 2
// Output:
// 3
// Explanation:
// The substrings are: "ab", "ba" and "aba".
// Example 2:

// Input: 
// S = "abaaca", K = 1
// Output:
// 7
// Explanation:
// The substrings are: "a", "b", "a", "aa", "a", "c", "a". 


// ! SOLUTION

long long int subwithk(string s,int k)
    {
        int arr[26]={0};
        long long int count=0;
        int distinct=0;
        int i,left=0;
        for(i=0;i<s.length();i++)
        {
            if(arr[s[i]-'a'] == 0)
                distinct++;
            arr[s[i]-'a']++;
            while(distinct>k)
            {
                arr[s[left]-'a']--;
                if(arr[s[left]-'a'] == 0)
                    distinct--;
                left++;
            }
            count+=i-left+1;
        }
        return count;
    }
    long long int substrCount (string s, int k) {
        //code here.
        return subwithk(s,k) - subwithk(s,k-1);
    }