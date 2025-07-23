/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int lsum = 0;
        for (int i = 0; i < m; ++i) {
            lsum += grid[i][0];
            dp[i][0] = lsum;
        }
        int tsum = 0;
        for (int j = 0; j < n; ++j) {
            tsum += grid[0][j];
            dp[0][j] = tsum;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

