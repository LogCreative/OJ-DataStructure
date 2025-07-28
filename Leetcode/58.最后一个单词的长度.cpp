/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        string last = "";
        bool flag = true;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (flag && s[i] == ' ') {
                continue;
            }
            if (s[i] != ' ') {
                if (flag) {
                    flag = false;
                }
                last = s[i] + last;
                continue;
            }
            if (!flag && s[i] == ' ') {
                break;
            }
        }
        return last.length();
    }
};
// @lc code=end

