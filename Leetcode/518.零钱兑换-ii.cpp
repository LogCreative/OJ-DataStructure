/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<int> valid(amount + 1);
        // valid[0] = 1;
        // for (int coin : coins) {
        //     for (int i = coin; i <= amount; ++i) {
        //         valid[i] |= valid[i-coin];
        //     }
        // }
        // if (!valid[amount]) return 0;

        vector<unsigned long long> dp(amount + 1);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

