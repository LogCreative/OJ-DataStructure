/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

#include<iostream>
#include<vector>
#include<set>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int s_size = s.length();
        int p_size = p.length();
        
        // string p_sorted = p;
        // sort(p_sorted.begin(), p_sorted.end());
        // for (int i=0; i<s_size-p_size+1; ++i) {
        //     string sub = s.substr(i, p_size);
        //     sort(sub.begin(), sub.end());
        //     if (sub.compare(p_sorted) == 0) {
        //         ans.push_back(i);
        //     }
        // }
        // return ans;

        if (p_size > s_size) {
            return ans;
        }

        vector<int> p_chars(26);
        for (auto c : p) {
            ++p_chars[c-'a'];
        }

        vector<int> s_chars(26);
        for (int i=0; i<p_size; ++i){
            ++s_chars[s[i]-'a'];
        }
        if (p_chars==s_chars) {
            ans.push_back(0);
        }

        for (int i=1; i<s_size-p_size+1; ++i) {
            // remove i-1
            --s_chars[s[i-1]-'a'];
            ++s_chars[s[i+p_size-1]-'a'];
            if (p_chars == s_chars) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
// @lc code=end

