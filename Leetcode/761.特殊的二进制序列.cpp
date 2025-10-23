/*
 * @lc app=leetcode.cn id=761 lang=cpp
 *
 * [761] 特殊的二进制序列
 */

#include<iostream>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    string makeLargestSpecial(string s) {
        // 11110000
        // 括号
        // 1....0
        // 分治，仅能交换两个相邻的特殊串

        int n = s.size();
        if (n <= 2) {
            return s;
        }

        int cnt = 0; int left = 0;
        vector<string> subs;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                cnt++;
            } else {
                cnt--;
                if (cnt == 0) {
                    // 特殊子串
                    subs.push_back("1" + makeLargestSpecial(
                        s.substr(left + 1, // 最左侧的1
                        i-left-1 // left 1    i
                    )) + "0");
                    left = i + 1;
                }
            }
        }

        sort(subs.begin(), subs.end(), greater<string>{});
        string ans;
        for (string sub : subs) {
            ans += sub;
        }
        return ans;
    }
};
// @lc code=end

