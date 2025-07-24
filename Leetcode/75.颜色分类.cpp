/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        // 0 0 x x x x 2 2 2
        //.  l.        r
        for (int pos = 0; pos <= right; ++pos) {
            while (pos <= right && nums[pos] == 2) {
                swap(nums[pos], nums[right]);
                right -= 1;
            }
            if (nums[pos] == 0) {
                int tmp = nums[left];
                nums[left] = 0;
                nums[pos] = tmp;
                left += 1;
            }
        }
    }
};
// @lc code=end

