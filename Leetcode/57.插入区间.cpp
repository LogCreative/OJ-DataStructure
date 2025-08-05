/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // s_i <= e_i
        // e_{i-1} <= s_i <= sn_i <= s_{i+1} <= e_{i+1} 
        int start_i = -1;
        int n = intervals.size();

        if (n == 0) {
            return vector<vector<int>>({newInterval});
        }

        for (int i = 0; i < n; ++i) {
            if (intervals[i][0] <= newInterval[0]) {
                if (i + 1 < n) {
                    if (intervals[i+1][0] >= newInterval[0]) {
                        start_i = i; break;
                    }
                } else {
                    if (intervals[i][1] >= newInterval[0]) {
                        start_i = i;
                    } else {
                        start_i = n;
                    }
                    break;
                }
            }
        }

        int search_i = start_i;
        if (start_i == -1) {
            search_i = 0;
        }
        int end_i = n;
        for (int i = search_i; i < n; ++i) {
            if (intervals[i][1] >= newInterval[1]) {
                end_i = i; break;
            }
        }

        vector<vector<int>> ans;
        int tmp_min;
        for (int i = 0; i < n; ++i) {
            if (i < start_i || i > end_i) {
                ans.push_back(intervals[i]);
            } else {
                if (start_i == -1) {
                    tmp_min = min(intervals[0][0], newInterval[0]);
                } else if (i == start_i) {
                    if (intervals[i][1] >= newInterval[0]) {
                        tmp_min = intervals[start_i][0];
                    } else {
                        tmp_min = newInterval[0];
                        ans.push_back(intervals[i]);
                    }
                }
                if (i == end_i) {
                    if (intervals[i][0] <= newInterval[1]) {
                        ans.push_back(vector<int>({tmp_min, intervals[i][1]}));
                    } else {
                        ans.push_back(vector<int>({tmp_min, newInterval[1]}));
                        ans.push_back(intervals[i]);
                    }
                }
            }
        }
        if (end_i == n) {
            if (start_i == n) {
                ans.push_back(newInterval);
            } else {
                ans.push_back(vector<int>({tmp_min, newInterval[1]}));
            }
        }

        return ans;
    }
};
// @lc code=end

