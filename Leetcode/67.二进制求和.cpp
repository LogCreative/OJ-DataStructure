/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
    string addBinaryBase(string a, string b) {
        string ans;
        int m = a.length();
        int n = b.length();
        int carry = 0;
        for (int i = 0; i < m; ++i) {
            int left = (i < m ? a[m - 1 - i] - '0' : 0);
            int right = (i < n ? b[n - 1 - i] - '0' : 0);
            int sum = left + right + carry;
            ans = to_string(sum % 2) + ans;
            carry = sum / 2;
        }
        if (carry > 0) {
            ans = to_string(carry) + ans;
        }
        return ans;
    }
public:
    string addBinary(string a, string b) {
        return a.length() > b.length() ? addBinaryBase(a,b) : addBinaryBase(b,a);
    }
};
// @lc code=end

