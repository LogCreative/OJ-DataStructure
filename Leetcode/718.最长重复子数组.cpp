/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // o o o x x x o o
        //.  o o x x x o o o
        return nums1.size() > nums2.size() ? findMax(nums1, nums2) : findMax(nums2, nums1);
    }

    int findMax(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        int ans = 0;
        // 滑动窗口
        //       x x x l2
        // x x x x
        //.    x x x x
        //.      x x x x
        //           x x x x
        for (int i = 0; i < l2; ++i) {
            ans = max(ans, findLen(nums1, nums2, l1-1-i, l1-1, 0, i));
        }
        for (int i = 0; i < l1 - l2; ++i) {
            ans = max(ans, findLen(nums1, nums2, l1-1-i-l2+1,l1-1-i, 0, l2-1));
        }
        for (int i = 0; i < l2; ++i) {
            ans = max(ans, findLen(nums1, nums2, 0, i, l2-1-i, l2-1));
        }
        return ans;
    }

    int findLen(vector<int>& nums1, vector<int>& nums2, int l1, int r1, int l2, int r2) {
        // [l1,r1]=[l2,r2]
        // [x x x o o]
        // []
        int cnt = 0, ans = 0;
        for (int i = 0; i <= r1-l1; ++i) {
            if (nums1[l1+i] == nums2[l2+i]) {
                ++cnt;
                ans = max(ans, cnt);
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
};
// @lc code=end

