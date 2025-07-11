/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int i) {
        if (i == nums.size()) {
            ans.push_back(t);
            return;
        }
        t.push_back(nums[i]);
        dfs(nums, i+1);
        t.pop_back();
        dfs(nums, i+1);
    }

    void backtracking(vector<int>& nums, int i) {
        vector<vector<int>> new_elements;
        for (auto unit : ans) {
            unit.push_back(nums[i]);
            new_elements.push_back(unit);
        }
        for (auto unit : new_elements) {
            ans.emplace_back(unit);
        }
        if (i+1<nums.size()) backtracking(nums, i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // ans.push_back(vector<int>({}));
        // backtracking(nums, 0);

        dfs(nums, 0);
        return ans;
    }
};
// @lc code=end

