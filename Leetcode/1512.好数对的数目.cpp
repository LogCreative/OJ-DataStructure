/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 *
 * [1512] 好数对的数目
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num : nums) {
            cnt[num]++;
        }

        int ans = 0;
        for (auto p : cnt) {
            if (p.second > 1) {
                ans += p.second * (p.second - 1) / 2;
            }
        }

        return ans;
    }
};
// @lc code=end

