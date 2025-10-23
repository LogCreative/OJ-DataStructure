/*
 * @lc app=leetcode.cn id=1610 lang=cpp
 *
 * [1610] 可见点的最大数目
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        // transform to polar degrees
        int sameCnt = 0;
        vector<double> polarDegrees;
        for (vector<int> & p : points) {
            if (p[0] == location[0] && p[1] == location[1]) {
                ++sameCnt;
            } else {
                polarDegrees.push_back(
                    atan2(p[1] - location[1], p[0] - location[0])
                );
            }
        }
        sort(polarDegrees.begin(), polarDegrees.end());

        int m = polarDegrees.size();
        for (int i = 0; i < m; ++i) {
            polarDegrees.push_back(polarDegrees[i] + 2 * M_PI);
        }

        int maxCnt = 0;
        int right = 0;
        double viewDegree = angle * M_PI / 180.0;
        for (int i = 0; i < m; ++i) {
            while (right < polarDegrees.size() && polarDegrees[right] <= polarDegrees[i] + viewDegree) {
                ++right;
            }
            maxCnt = max(maxCnt, right - i);
        }
        return maxCnt + sameCnt;
    }
};
// @lc code=end

