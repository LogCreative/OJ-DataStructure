/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        while (n > 0) {
            ans += n % 2;
            n >>= 1;
        }
        return ans;
    }
};
// @lc code=end

