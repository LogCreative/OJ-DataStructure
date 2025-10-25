/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n<2) {
            return 0;
        }
        int ans = 0;
        int cur = prices[0];
        for (int i = 1; i < n; ++i) {
            int p = prices[i];
            if (p < cur) {
                cur = p;
            }
            if (p - fee > cur) { // 有利润
                ans += p - cur - fee;
                cur = p - fee; // 避免重复扣费，反悔了
            }
        }
        return ans;
    }
};
// @lc code=end

