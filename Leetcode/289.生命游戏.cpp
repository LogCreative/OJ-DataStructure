/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
    int usedToLive(int state) {
        if (state == -1 || state == 1) {
            return 1;
        }
        return 0;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int live_cells;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                live_cells = 0;
                if (i >= 1 && j >= 1) live_cells += usedToLive(board[i-1][j-1]);
                if (i >= 1) live_cells += usedToLive(board[i-1][j]);
                if (i >= 1 && j + 1 < n) live_cells += usedToLive(board[i-1][j+1]);
                if (j >= 1) live_cells += usedToLive(board[i][j-1]);
                if (j + 1 < n) live_cells += usedToLive(board[i][j+1]);
                if (i + 1 < m && j >= 1) live_cells += usedToLive(board[i+1][j-1]);
                if (i + 1 < m) live_cells += usedToLive(board[i+1][j]);
                if (i + 1 < m && j + 1 < n) live_cells += usedToLive(board[i+1][j+1]);

                if (board[i][j] == 1  && live_cells < 2) board[i][j] = -1;
                if (board[i][j] == 1 && (live_cells == 2 || live_cells == 3)) board[i][j] = 1;
                if (board[i][j] == 1 && live_cells > 3) board[i][j] = -1;
                if (board[i][j] == 0 && live_cells == 3) board[i][j] = 2;
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = board[i][j] <= 0 ? 0 : 1;
            }
        }

        // 规则 1：如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡。这时候，将细胞值改为 -1，代表这个细胞过去是活的现在死了；

        // 规则 2：如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活。这时候不改变细胞的值，仍为 1；

        // 规则 3：如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡。这时候，将细胞的值改为 -1，代表这个细胞过去是活的现在死了。可以看到，因为规则 1 和规则 3 下细胞的起始终止状态是一致的，因此它们的复合状态也一致；

        // 规则 4：如果死细胞周围正好有三个活细胞，则该位置死细胞复活。这时候，将细胞的值改为 2，代表这个细胞过去是死的现在活了。
    }
};
// @lc code=end

