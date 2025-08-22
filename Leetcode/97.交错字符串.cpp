/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int l = s3.length();
    
        if (n+m!=l) {
            return false;
        }

        // 因为这里数组 f 的第 i 行只和第 i−1 行相关
        vector<bool> f(m+1, false);
        f[0] = true;

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) {
                    f[j] = f[j] && (s1[i-1]==s3[p]);
                }
                if (j > 0) {
                    f[j] = f[j] || (f[j-1] && s2[j-1]==s3[p]);
                }
            }
        }

        return f[m];
    }
};
// @lc code=end

