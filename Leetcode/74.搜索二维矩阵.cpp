/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row_left, left, right, mid, mid_ele;
        if (m == 1) {
            if (matrix[0][0] > target) return false;
            else row_left = 0;
        } else {
            // 左边找到第一个比它小的，右边找第一个比它大的。
            left = 0; right = m - 1;
            while (left < right) {
                mid = (left + right) / 2;
                mid_ele = matrix[mid][0];
                if (mid_ele == target) return true;
                if (mid_ele < target) left = mid + 1;
                if (mid_ele > target) right = mid - 1;
            }
            row_left = matrix[left][0] <= target ? left : left - 1;
            if (row_left < 0) return false;
        }

        left = 0; right = n - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            mid_ele = matrix[row_left][mid];
            if (mid_ele == target) return true;
            if (mid_ele < target) left = mid + 1;
            if (mid_ele > target) right = mid - 1;
        }
        return false;

        // left = 0; right = m - 1;
        // while (left <= right) {
        //     mid = (left + right) / 2;
        //     mid_ele = matrix[mid][n];
        //     if (mid_ele == target) return true;
        //     if (mid_ele < target) left = mid + 1;
        //     if (mid_ele > target) right = mid - 1;
        // }
    }
};
// @lc code=end

