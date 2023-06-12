#include<bits/stdc++.h>
using namespace std;

// *   Given a String S, reverse the string without reversing its individual words. 
// *   Words are separated by dots.

// *   Example 1:

// *   Input:
// *   S = i.like.this.program.very.much
// *   Output: much.very.program.this.like.i
// *   Explanation: After reversing the whole
// *   string(not individual words), the input
// *   string becomes
// *   much.very.program.this.like.i

string reverseWords(string sentence)
{
    string res="";
    string temp="";

    for(int i=0;i<sentence.size();i++)
    {
        
        if(sentence[i]=='.')
        {
            res='.'+temp+res;
            temp="";
        }
        else temp+=sentence[i];
    }
    return temp+res;
}