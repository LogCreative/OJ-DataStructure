/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
    static bool cmp(vector<int>& left, vector<int>& right) {
        return left[0] < right[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1) {
            return 1;
        }

        sort(points.begin(), points.end(), cmp);
        
        int ans = n;
        for (int i = 1; i < n; ++i) {
            if (points[i][0] <= points[i-1][1]) {
                --ans;
                points[i][0] = max(points[i][0], points[i-1][0]);
                points[i][1] = min(points[i][1], points[i-1][1]);
            }
        }

        return ans;
    }
};
// @lc code=end

