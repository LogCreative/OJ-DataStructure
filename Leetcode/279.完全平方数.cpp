/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        // int rt = sqrt(n); // 下取整
        // 1^2 = 1
        // n = \sum a_i^2
        // n - a_j^2 = \sum a
        // f(n) = f(n-a_j^2) + 1(a_j^2), a_j varies from sqrt(n) to 1
        
        vector<int> f(n+1);
        for (int i = 1; i <= n; ++i) {
            int minn = INT_MAX;
            int cur_top = sqrt(i);
            for (int j = 1; j <= cur_top; ++j) {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];

    }
};
// @lc code=end

