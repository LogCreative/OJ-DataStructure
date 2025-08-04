/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> cur_scanned;

        //     1 1 1 1 1
        // x x o x x

        if (n == 1) {
            return false;
        }

        for (int j = 1; j <= k && j < n; ++j) {
            ++cur_scanned[nums[j]];
        }

        for (int i = 0; i < n; ++i) {
            int cur = nums[i];
            if (cur_scanned.find(cur) != cur_scanned.end() && cur_scanned[cur]>0) {
                return true;
            }
            // remove the left most
            if (i - k >= 0) {
                --cur_scanned[nums[i-k]];
            }
            // add the right most
            if (i + k + 1 < n) {
                ++cur_scanned[nums[i+k+1]];
            }
            // add the self
            ++cur_scanned[cur];
            // remove the next
            if (i+1<n) --cur_scanned[nums[i+1]];
        }
        return false;
        // 可以用 unordered_set 在元素插入之前判断以优化
    }
};
// @lc code=end

