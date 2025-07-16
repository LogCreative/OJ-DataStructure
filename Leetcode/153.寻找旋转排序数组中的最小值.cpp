/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int left = 0, right = n - 1;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] < nums[right]) {
                right = mid; // 视作折线图
            } else {
                left = mid + 1;
            }
        }
        return nums[right]; // 特殊判定
    }
};
// @lc code=end

