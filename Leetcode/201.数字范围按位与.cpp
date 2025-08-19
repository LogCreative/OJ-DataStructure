/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // 该位置上有没有出现0, Brian Kernighan 去除右侧的 1
        while (left < right) {
            right = right & (right - 1);
        }
        return right;
    }
};
// @lc code=end

