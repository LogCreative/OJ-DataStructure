/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // f(x) = min f(x-c_j) + 1, where f(x-c_j)>=0
        vector<int> f(amount+1);
        f[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            int minf = INT_MAX;
            for (int coin : coins) {
                if (i - coin >= 0 && f[i-coin] >= 0) {
                    minf = min(minf, f[i-coin]);
                }
            }
            if (minf == INT_MAX) {
                f[i] = -1;
            } else {
                f[i] = minf + 1;
            }
        }
        return f[amount];
    }
};
// @lc code=end

