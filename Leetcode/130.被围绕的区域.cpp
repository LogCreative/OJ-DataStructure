/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
    int m, n;

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] != 'O') {
            return ;
        }
        board[x][y] = 'A';
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
        dfs(board, x - 1, y);
        dfs(board, x + 1, y);
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        
        // 标记与边缘连通的 O
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bool isEdge = (i == 0 || j == 0 || i == m - 1 || j == n - 1);
                if (isEdge && board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }  
            }
        }
    }
};
// @lc code=end

