/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // f(s) = f(s-w_i) [+ w_i]
        int n = s.size();
        int m = wordDict.size();
        
        vector<bool> f(n+1, 0);
        f[0] = 1;
        for (int i = 1; i <= n ; ++i) {
            for (int j = 0; j < m; ++j) {
                int ws = wordDict[j].size();
                if (i < ws) {
                    continue;
                }

                string tmp = s.substr(i - ws, ws);
                if (tmp == wordDict[j] && f[i-ws]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};
// @lc code=end

