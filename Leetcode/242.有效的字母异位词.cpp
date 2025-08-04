/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        unordered_map<char, int> s_cnt;
        unordered_map<char, int> t_cnt;
        for (char c : s) {
            ++s_cnt[c];
        }
        for (char c : t) {
            ++t_cnt[c];
        }
        for (auto c_i : s_cnt) {
            if (t_cnt.find(c_i.first) != t_cnt.end()) {
                if (t_cnt[c_i.first] != c_i.second) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

