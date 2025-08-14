/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int preMax = nums[0]; int maxRes = nums[0];
        int preMin = nums[0]; int minRes = nums[0];
        int sum = nums[0];
        for (int i = 1; i < n; ++i) {
            preMax = max(preMax + nums[i], nums[i]);
            maxRes = max(maxRes, preMax);
            preMin = min(preMin + nums[i], nums[i]);
            minRes = min(minRes, preMin);
            sum += nums[i];
        }
        if (maxRes < 0) {
            return maxRes;
        }
        return max(maxRes, sum - minRes);
    }
};
// @lc code=end

