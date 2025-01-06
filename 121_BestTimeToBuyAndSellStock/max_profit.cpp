// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // set initial buy price to day 1 price
        int buy_price = prices[0];
        // initialize max profit to 0
        int max_profit = 0;

        // iterate through each price
        for(int i = 0; i < prices.size(); i++)
        {
            // check if we have found a lower potential buy price
            if(prices[i] < buy_price)
            {
                // update lowest possible buy price for following days
                buy_price = prices[i];
            } 
            // otherwise, check profit for selling on this day
            else if(prices[i] - buy_price > max_profit)
            {
                // update max potential profit
                max_profit = prices[i] - buy_price;
            }
        }

        return max_profit;
    }
};

int main() {
    Solution solution;

    // Input vector size
    cout << "Enter the number of days (size of prices array): ";
    int n;
    cin >> n;

    // Input prices array
    vector<int> prices(n);
    cout << "Enter the prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // Call maxProfit function
    int result = solution.maxProfit(prices);

    // Output the result
    cout << "Maximum profit: " << result << endl;

    return 0;
}