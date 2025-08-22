/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> f(m, vector<int>(n, 0));

        int l = 0;
        if (matrix[0][0] == '1') {
            f[0][0] = 1;
            l = max(l, 1);
        }

        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == '1') {
                f[i][0] = 1;
                l = max(l, 1);
            } else {
                f[i][0] = 0;
            }
        }
        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == '1') {
                f[0][j] = 1;
                l = max(l, 1);
            } else {
                f[0][j] = 0;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    f[i][j] = min(min(f[i-1][j-1],f[i-1][j]),f[i][j-1]) + 1;
                }
                l = max(l, f[i][j]);
            }
        }

        return l * l;
    }
};
// @lc code=end

