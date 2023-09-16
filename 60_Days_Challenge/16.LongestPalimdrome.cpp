#include <bits/stdc++.h>
using namespace std;


// ! QUESTION

// Given a string s which consists of lowercase or uppercase letters, 
// return the length of the longest palindrome that can be built with those letters.
// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

// Example 1:

// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
// Example 2:

// Input: s = "a"
// Output: 1
// Explanation: The longest palindrome that can be built is "a", whose length is 1.


// ! SOLUTION

// * MY APPROACH

 int longestPalindrome(string s) {
        unordered_map<char,int>m;

        for(char c:s)m[c]++;
        int res=0;

        for(auto i:m)
        {
            res+=int((i.second)/2)*2;
        }
        if(s.size()!=res) return res+1;

        return res;
        
    }


// * ANOTHER APROACH



int longestPalindrome(string s) {
        unordered_map<char,int> map;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }
        int cnt=0;
        for(auto i:map){
            if(i.second%2!=0){
                cnt++;
            }
        }
        if(cnt>1){
            return s.length()-cnt+1;
        }
        return s.length();
    }