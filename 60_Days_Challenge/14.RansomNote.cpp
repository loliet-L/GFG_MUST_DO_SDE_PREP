#include<bits/stdc++.h>
using namespace std;

// ! QUESTION

// Given two strings ransomNote and magazine, return true if ransomNote can be 
// constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote. 

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true

// ! SOLUTION

 bool canConstruct(string ransomNote, string magazine) {
        
        if(ransomNote.size()>magazine.size())return false;
        
        unordered_map<char,int>m;
        
        for(char i:magazine)m[i]++;

        for(char c:ransomNote){
            if(m[c]==0 || m.find(c)==m.end()) return false;
            m[c]--;
        }

        return true ;
    }