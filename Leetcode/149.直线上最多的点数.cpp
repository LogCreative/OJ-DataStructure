/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

#include<iostream>
#include<math>
using namespace std;

// @lc code=start
class Solution {
    string normalizedSlope(int a, int b) {
        if (b < 0) {
            a = -a;
            b = -b;
        }
        int divider = (b == 0 ? a : gcd(a, b));
        return to_string(a/divider) + ',' + to_string(b/divider);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        int ans = 2;
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> slope_cnt;
            for (int j = i + 1; j < n; ++j) {
                slope_cnt[normalizedSlope(points[j][0]-points[i][0], points[j][1]-points[i][1])]++;
            }
            for (auto slope : slope_cnt) {
                ans = max(ans, slope.second + 1);
            }
        }

        return ans;
    }
};
// @lc code=end

