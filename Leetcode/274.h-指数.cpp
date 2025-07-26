/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        // 0 1 3 5 6
        // 1 1 3
        int h = 0, left = 0, ans = 0;
        while (left < n && h <= n) {
            if (citations[left] >= h) {
                if (n - left >= h) {
                    ans = h;
                    ++h;
                } else {
                    break;
                }
            } else {
                ++left;
            }
        }
        return ans;
    }

    // 二分是最好的，<=h 都满足，>h不满足，[mid,right] 和 [0,mid)
};
// @lc code=end

