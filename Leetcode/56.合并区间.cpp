/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

#include<iostream>
using namespace std;


// @lc code=start
class Solution {
public:
    static bool compare(const vector<int> &l, const vector<int> &r) {
        return l[0] < r[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> ans;
        vector<int> current = intervals[0];
        for (auto & interval : intervals) {
            if (interval == current) {
                continue;
            }
            if (interval[0] <= current[1]) {
                current = vector<int>({current[0], max(current[1], interval[1])});
            } else {
                ans.push_back(current);
                current = interval;
            }
        }
        ans.push_back(current);
        return ans;
    }
};
// @lc code=end

