/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int sum = 0;
        int ans = INT_MAX;
        int left = 0, right = 0;
        while (right < n) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                ++left;
            }
            ++right;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end

