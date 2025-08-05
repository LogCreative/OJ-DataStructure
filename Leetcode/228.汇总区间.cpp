/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if (n == 0) return ans;
        long long prev_s = nums[0];
        long long prev = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] - prev > 1) {
                if (prev - prev_s == 0) {
                    ans.push_back(to_string(prev));
                } else {
                    ans.push_back(to_string(prev_s) + "->" + to_string(prev));
                }
                prev_s = nums[i];
            }
            prev = nums[i];
        }
        if (prev - prev_s == 0) {
            ans.push_back(to_string(prev));
        } else {
            ans.push_back(to_string(prev_s) + "->" + to_string(prev));
        }
        return ans;
    }
};
// @lc code=end

