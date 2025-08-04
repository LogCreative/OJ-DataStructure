/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
    bool isIsomorphic_base(string s, string t) {
        int n = s.size();
        unordered_map<char, char> c_map;
        for (int i = 0; i < n; ++i) 
        {
            char s_c = s[i];
            char t_c = t[i];
            if (c_map.find(s_c) == c_map.end()) {
                c_map[s_c] = t_c;
            } else {
                char target_t_c = c_map[s_c];
                if (t_c != target_t_c) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isIsomorphic(string s, string t) {
        return isIsomorphic_base(s,t) && isIsomorphic_base(t,s);
    }
};
// @lc code=end

