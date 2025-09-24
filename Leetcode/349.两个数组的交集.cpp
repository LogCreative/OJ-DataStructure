/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

#include<iostream>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int num : nums2) {
            if (set1.erase(num)) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};
// @lc code=end

