/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            vector<bool> visited(10, false);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int cur = board[i][j] - '0';
                if (visited[cur]) return false;
                visited[cur] = true;
            }
        }
        for (int j = 0; j < 9; ++j) {
            vector<bool> visited(10, false);
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] == '.') continue;
                int cur = board[i][j] - '0';
                if (visited[cur]) return false;
                visited[cur] = true;
            }
        }
        for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
                vector<bool> visited(10, false);
                for (int i = k * 3 + 0; i < k * 3 + 3; ++i) {
                    for (int j = l * 3 + 0; j < l * 3 + 3; ++j) {
                        if (board[i][j] == '.') continue;
                        int cur = board[i][j] - '0';
                        if (visited[cur]) return false;
                        visited[cur] = true;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

