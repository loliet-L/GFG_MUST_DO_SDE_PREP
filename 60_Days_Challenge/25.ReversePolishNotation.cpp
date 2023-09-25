#include<bits/stdc++.h>
using namespace std;


// ! QUESTION

// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.
 
// Example 1:

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
// Example 2:

// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6

// ! SOLUTION


 void solve(stack<long long> &st,string s){
        long long b=st.top();st.pop();
        long long a=st.top();st.pop();
        if(s=="+"){
            st.push(a+b);
        }
        else if(s=="-"){
            st.push(a-b);
        }
        else if(s=="*"){
            st.push(a*b);
        }
        else{
            st.push(a/b);
        }
    }
    int evalRPN(vector<string>& nums) {
        int n=nums.size();
        stack<long long> st;
        for(int i=0;i<n;i++){
            if(nums[i]=="+" || nums[i]=="-" || nums[i]=="*" || nums[i]=="/"){
                solve(st,nums[i]);
            }
            else{
                st.push(stol(nums[i]));
            }
        }
        return st.top();
    }