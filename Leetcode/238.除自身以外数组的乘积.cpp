/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int pre = 1, suf = 1;
        for (int i = 0; i < n; ++i) {
            ans[i] = pre;
            pre *= nums[i];
        }
        // [1, a0, a0a1, ..., a0a1..an-1]
        for (int j = n - 1; j >= 0; --j) {
            ans[j] *= suf;
            suf *= nums[j];
        }
        return ans;
    }
};
// @lc code=end

