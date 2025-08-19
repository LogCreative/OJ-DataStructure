/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = x ^ y;
        // return __builtin_popcount(dist);
        int ans = 0;
        while (dist > 0) {
            dist = dist & (dist - 1);
            ++ans;
        }
        return ans;
    }
};
// @lc code=end

