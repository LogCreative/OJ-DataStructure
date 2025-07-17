/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if (numRows == 1) return ans;
        ans.push_back({1,1});
        if (numRows == 2) return ans;
        for (int i = 2; i < numRows; ++i) {
            vector<int> curRow;
            curRow.push_back(1);
            // ans[i,j] = ans[i-1,j-1] + ans[i-1,j]
            for (int j = 1; j < i; ++j) {
                curRow.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            curRow.push_back(1);
            ans.push_back(curRow);
        }
        return ans;
    }
};
// @lc code=end

