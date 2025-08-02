/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> ransomAlpha(26, 0);
        vector<int> magAlpha(26, 0);
        for (char c : ransomNote) {
            ++ransomAlpha[c - 'a'];
        }
        for (char c : magazine) {
            ++magAlpha[c - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (ransomAlpha[i] > magAlpha[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

