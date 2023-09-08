#include<bits/stdc++.h>
using namespace std;

// ! QUESTION

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
// typically using all the original letters exactly once.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false




// ! using sort

bool isAnagram(string s, string t) {
  if(s.size()!=t.size())return false;
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());

  return s==t;
}


// ! using map

bool isAnagram(string s, string t) {
unordered_map<char, int> umap;
for(auto i:s){
umap[i]++;
}
for(auto i:t){
umap[i]--;
if(umap[i] == 0)
umap.erase(i);
}
return umap.empty();
}


// ! without using map

//Time Complexity:O(n), Space Complexity:O(1);
bool isAnagram(string s, string t) {
int slength;
int tlength;
int alphabet[26]={0};

    //If they're not the same size, they're not an anagram
    if((slength=s.size())!=(tlength=t.size())){
       return false;
    }
       
    /*Adding the to the index that
    corresponds to a letter in s and 
    subtracting from the index that corresponds
    to a letter in t (Should equate to 0 if they are anagrams)*/
     for(int i=0;i<slength;i++){
       alphabet[s[i]-'a']++;
       alphabet[t[i]-'a']--;
      }
    //Check if alphabet array has any number but a 0
    for(int i=0;i<26;i++){
      if(alphabet[i]!=0){
            return false;
        }
    }
    return true;
}