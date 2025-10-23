/*
 * @lc app=leetcode.cn id=1209 lang=cpp
 *
 * [1209] 删除字符串中的所有相邻重复项 II
 */

#include<iostream>
#include<string>
#include<stack>
using namespace std;

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;
        for (char c : s) {
            if (!stk.empty() && stk.top().first == c) {
                if (stk.top().second + 1 == k) {
                    while (!stk.empty() && stk.top().first == c) {
                        stk.pop();
                    }
                } else {
                    stk.push({c, stk.top().second + 1});
                }
            } else {
                stk.push({c, 1});
            }
        }
        string ans;
        while (!stk.empty()) {
            ans.push_back(stk.top().first);
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

