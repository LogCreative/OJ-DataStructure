/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        // 10 = 2 * 5 = 1 * 10 
        // fix: 不断除以 5.
        int ans = 0;
        int ans2 = 0;
        int ans5 = 0;
        for (int i = 1; i <= n; ++i) {
            // 素因数分解
            int tmp = i;
            while (tmp >= 2) {
                if (tmp % 10 == 0) {
                    ++ans;
                    tmp /= 10;
                } else if (tmp % 2 == 0) {
                    ++ans2;
                    tmp /= 2;
                } else if (tmp % 5 == 0) {
                    ++ans5;
                    tmp /= 5;
                } else {
                    break;
                }
            }
        }
        ans += min(ans2, ans5);
        return ans;
    }
};
// @lc code=end

