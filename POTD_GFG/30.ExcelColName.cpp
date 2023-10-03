#include<bits/stdc++.h>
using namespace std;


// ! QUESTION

// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
// Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc. 
// In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA” and so on.

// Example 1:

// Input:
// N = 28
// Output: AB
// Explanation: 1 to 26 are A to Z.
// Then, 27 is AA and 28 = AB.

// Example 2:

// Input: 
// N = 13
// Output: M
// Explanation: M is the 13th character of
// alphabet.

// ! SOLUTION

// ! APPROACH 1

string colName (long long int n)
    {
        string ans;
        while(n){
            int c=(n-1)%26;
            ans.push_back(char('A'+c));
            n=(n-1)/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }


    // ! APPROACH 2

 string colName (long long int n)
    {
        string res="";
        
        while(n)
        {
            n--;
            int y=n%26;
            res=char(65+y)+res;
            n/=26;
        }
        
        return res;
    }