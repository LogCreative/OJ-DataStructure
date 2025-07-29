/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int integerReplacement(int n) {
        // x x x x -> 1
        // 1 0 1 0 -> 1 0 1 ->  n >> 1 
        // 1 0 1 1 -> 1 0 1 0
        if (n==1) {
            return 0;
        }
        if (n % 2 == 0) {
            return 1 + integerReplacement(n/2);
        }
        return 2 + min(integerReplacement(n/2), integerReplacement(n/2+1)); // 防止溢出

        // 更巧妙的是分类讨论 % 4
    }
};
// @lc code=end

