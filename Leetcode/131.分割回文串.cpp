/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
    vector<vector<bool>> f;
    vector<vector<string>> ans;
    vector<string> one;
    int n;

    void dfs(const string &s, int i) {
        if (i == n) {
            ans.push_back(one);
            return ;
        }

        for (int j = i; j<n; ++j) {
            if (f[i][j]) {
                one.push_back(s.substr(i, j-i+1));
                // 考虑这段之后的逗号怎么选
                dfs(s, j+1);
                one.pop_back();
            }
        }

    }

public:
    vector<vector<string>> partition(string s) {
        // f(i,j) = f(i+1,j-1) ^ s[i]==s[j]
        
        n = s.size();
        f.assign(n, vector<bool>(n, true));
        
        for (int i = n-2; i >= 0; --i) {
            for (int j = i+1; j < n; ++j) {
                f[i][j] = (s[i] == s[j]) && f[i+1][j-1];
            }
        }

        dfs(s, 0);

        return ans;
    }
};
// @lc code=end

