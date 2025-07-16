/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int num : nums) {
            ++cnt[num];
        }

        priority_queue<pair<int, int>> pq;
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            pq.push(make_pair(it->second, it->first));
        }

        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end

