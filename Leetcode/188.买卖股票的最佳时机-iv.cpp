/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> dp(2 * k, 0);
        for (int i = 0; i < k; ++i) {
            dp[2 * i] = -prices[0];
        }
        int n = prices.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                dp[2*j] = max(dp[2*j], (j > 0 ? dp[2*j-1] : 0) - prices[i]);
                dp[2*j + 1] = max(dp[2*j+1], dp[2*j] + prices[i]);
            }
        }
        return dp[2*k-1];
    }
};
// @lc code=end

