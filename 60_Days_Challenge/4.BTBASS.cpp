#include "bits/stdc++.h"
using namespace std;

// Best Time to Buy and Sell Stock Easy
// You are given an array prices where prices[i] is the price of a given
// stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one 
// stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction.
// If you cannot achieve any profit, return 0

//  * MY SOLUTION

// ! MY APPROACH

// Let's consider an example of [4,1,5,2,7]
// 4 is the cheapest price we see to start, and we can't sell on the first day so maxProfit is 0
// 1 is now the cheapest price we've seen. Selling now would lose us money, so we can't update maxProfit
// 5 is not cheaper than 1, but if we sell now we get a maxProfit of 4! Better save that for later
// 2 is not cheaper than 1 and if we sell, we only get a profit of 1, no need to do anything here
// 7 is not cheaper than 1, but if we sell here, we'll increase maxProfit to 6, making this the best profit to return.

int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int cheaper=prices[0];

        for(auto i: prices)
        {
            if((i-cheaper)>maxProfit) maxProfit=(i-cheaper);
            if(i<cheaper) cheaper=i;
        }
        return maxProfit;
         
        
    }


    // * USING KADANES ALGORITHM


    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int currProfit=0;
        for ( int i =1 ; i < prices.size() ;i++)
        {
            currProfit += prices[i]-prices[i-1];
            if(currProfit > maxProfit)
            {
                maxProfit = currProfit;
            }
            if(currProfit < 0){
                currProfit =0;
            }
        }
        return maxProfit;
    }