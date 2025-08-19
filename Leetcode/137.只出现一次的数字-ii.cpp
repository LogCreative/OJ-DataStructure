/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // (1 + 1 + 1) mod 3 = 0, (0 + 0 + 0) mod 3 = 0
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int total = 0;
            for (auto num : nums) {
                total += (num >> i) & 1;
            }
            if (total % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};
// @lc code=end

