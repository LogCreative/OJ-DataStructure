/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> f0(n), f1(n);
        // 0 1 ..... 0/1
        f0[0] = 0;
        f0[1] = nums[1];
        // 1 0 ... 0
        f1[0] = nums[0];
        f1[1] = nums[0];
        for (int i = 2; i < n; ++i) {
            f0[i] = max(f0[i-2] + nums[i], f0[i-1]);
            f1[i] = (i < n - 1 ? max(f1[i-2] + nums[i], f1[i-1]) : max(f1[i-2], f1[i-1]) );
        }
        return max(f0[n-1], f1[n-1]);
    }
};
// @lc code=end

