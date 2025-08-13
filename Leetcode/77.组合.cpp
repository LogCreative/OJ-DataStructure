/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

#include<iostream>
using namespace std;
 
// @lc code=start
class Solution {
    void backtrace(int i, int n, int k, vector<int> &combination, vector<vector<int>>& res) {
        if (combination.size() == k) {
            res.emplace_back(combination);
            return;
        }
        for (i = i + 1; i <= n; ++i) {
            combination.emplace_back(i);
            backtrace(i, n, k, combination, res);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        // if (k == 1) {
        //     vector<vector<int>> ans;
        //     for (int i = 1; i <= n; ++i) {
        //         ans.push_back({i});
        //     }
        //     return ans;
        // }
        // if (n < k) {
        //     return {};
        // }

        // vector<vector<int>> p1 = combine(n-1, k-1);
        // int len = p1.size();
        // for (int i = 0; i < len; ++i) {
        //     p1[i].push_back(n);
        //     // for (auto m : p1[i]) {
        //     //     cout << m << ' ';
        //     // }
        //     // cout << endl;
        // }

        // vector<vector<int>> p2;
        // if (k <= n-1) {
        //     p2 = combine(n-1, k);
        // } else {
        //     p2 = {};
        // }

        // for (auto p : p2) {
        //     p1.push_back(p);
        // }
        // return p1;

        // 为了减少内存占用，可以先推入，再推出地dfs
        vector<vector<int>> res;
        vector<int> combination;
        backtrace(0, n, k, combination, res);
        return res;
        
    }
};
// @lc code=end

