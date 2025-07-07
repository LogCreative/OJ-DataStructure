/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:

    // bool isAllZero(vector<int> v) {
    //     for(auto i=v.begin(); i < v.end(); ++i) {
    //         if (*i > 0) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    unordered_map<char, int> ori, cnt;

    bool check() {
        for (auto &p : ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {

        int m = s.length();
        int n = t.length();

        if (m < n) {
            return "";
        }

        for (auto &c: t) {
            ++ori[c];
        }

        int j = 0, k = 0;
        ++cnt[s[0]];
        int ansL = -1, ansR = -1;
        while(k<m) {
            if (check()) {
                if (ansL < 0 || ansR < 0 || ansR - ansL > k-j) {
                    ansL = j;
                    ansR = k;
                }
                if (ori.find(s[j]) != ori.end()){
                    --cnt[s[j]];
                }
                ++j;
            } else {
                ++k;
                if (ori.find(s[k]) != ori.end()) {
                    ++cnt[s[k]];
                }
            }
        }
        
        return ansL < 0 ? "" : s.substr(ansL, ansR-ansL+1);
    }
};
// @lc code=end

