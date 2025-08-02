/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int real_target, left, right, mid;
        int prev_num = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (numbers[i] == prev_num) {
                continue;
            }
            prev_num = numbers[i];
            real_target = target - numbers[i];
            left = i+1; right = n - 1;
            while (left <= right) {
                mid = left + (right - left) / 2;
                if (numbers[mid] == real_target) {
                    return vector<int>({i+1, mid+1});
                }
                if (numbers[mid] < real_target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return vector<int>(1,2);
        // 双指针更好
    }
};
// @lc code=end

