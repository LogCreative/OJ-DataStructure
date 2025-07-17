/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        // v o   1   2   repeat
        // i i+1 i+2 i+3
        // not above

        // f(i) = max(f(i-2) + nums[i], f(i-1))

        int n = nums.size();
        vector<int> f(n);
        if (n == 1) return nums[0];
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            f[i] = max(f[i-2] + nums[i], f[i-1]);
        }
        return f[n-1];

    }
};
// @lc code=end

