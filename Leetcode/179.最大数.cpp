/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

#include<iostream>
#include<numeric>
using namespace std;

// @lc code=start
class Solution {
    static bool cmp(int &l, int &r) {
        string left = to_string(l);
        string right = to_string(r);
        int l_l = left.length();
        int r_l = right.length();
        int minl = min(l_l, r_l);
        int maxl = gcd(l_l, r_l);
        maxl = l_l / maxl * r_l;
        for (int i = 0; i < maxl; ++i) {
            char l_c = left[i % l_l];
            char r_c = right[i % r_l];
            if (l_c == r_c) {
                continue;
            }
            return l_c > r_c;
        }
        return false; // left = right.

        // return left + right > right + left;
    }
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        for (int i = 0; i < n; ++i) {
            ans += to_string(nums[i]);
        }
        int pos = -1;
        int len = ans.size();
        for (int i = 0; i < len; ++i) {
            if (ans[i] == '0') {
                pos = i;
            } else {
                break;
            }
        }
        if (pos == len - 1) {
            return "0";
        }
        if (pos >= 0) { // 0 0 1
            ans = ans.substr(pos + 1, len - pos - 1);
        }
        return ans;
    }
};
// @lc code=end

