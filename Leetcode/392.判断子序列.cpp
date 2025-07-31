/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (m == 0) {
            return true;
        }
        int i = 0;
        for (int j = 0; j < n; ++j) {
            if (s[i] == t[j]) {
                ++i;
                if (i >= m) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

