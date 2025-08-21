/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> f(m, vector<int>(n, 0));

        if (obstacleGrid[0][0]) {
            return 0;
        }

        f[0][0] = 1;
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j]) {
                break;
            } else {
                f[0][j] = 1;
            }
        }
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0]) {
                break;
            } else {
                f[i][0] = 1;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = obstacleGrid[i][j] ? 0 : (f[i][j-1] + f[i-1][j]);
            }
        }

        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << f[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        return f[m-1][n-1];
    }
};
// @lc code=end

