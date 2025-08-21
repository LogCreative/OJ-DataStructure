/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
    int n;

    // int dfs(vector<vector<int>>& triangle, int left, int level, int sum) {
    //     if (level == n) {
    //         return sum;
    //     }
    //     sum += triangle[level][left];
    //     // left, left + 1
    //     int ans = dfs(triangle, left, level + 1, sum);
    //     if (left < level + 1) {
    //         ans = min(ans, dfs(triangle, left + 1, level + 1, sum));
    //     }
    //     return ans;
    // }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // [.]        s
        // [. .].     x
        // [. . .]
        // [. . . .]. y
        n = triangle.size();
        // return dfs(triangle, 0, 0, 0);

        vector<vector<int>> f(2, vector<int>(n));
        f[0][0] = triangle[0][0];

        // f(i,j) = min(f(i-1, j), f(i-1, j-1)) + t[i][j]
        for (int i = 1; i < n; ++i) {
            int cur = i % 2;
            int prev = 1 - cur;
            f[cur][0] = f[prev][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                f[cur][j] = min(f[prev][j], f[prev][j-1]) + triangle[i][j];
            }
            f[cur][i] = f[prev][i-1] + triangle[i][i];
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, f[(n-1) % 2][i]);
        }
        return ans;
    }
};
// @lc code=end

