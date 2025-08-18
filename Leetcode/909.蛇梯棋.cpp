/*
 * @lc app=leetcode.cn id=909 lang=cpp
 *
 * [909] 蛇梯棋
 */

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
    int n;
    pair<int, int> getCoord(int x) {
        int row = (x - 1) / n;
        int col = (x - 1) % n;
        col = (row % 2) ? (n - 1 - col) : col;
        return {n - 1 - row, col};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int n2 = n * n;

        vector<int> visited(n2 + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = true;

        int ans = INT_MAX;

        while (!q.empty()) {
            auto [curr, prevStep] = q.front(); q.pop();
            pair<int,int> pos = getCoord(curr);
            // int ladder = board[pos.first][pos.second];
            for (int i = curr + 1; i <= curr + 6 && i <= n2; ++i) {
                pair<int, int> next = getCoord(i);
                int nxt = i;
                int next_ladder = board[next.first][next.second];
                if (next_ladder != -1) {
                    nxt = next_ladder;
                    // cout << next_ladder << ' ' << "true" << ' ' << prevStep + 1 << endl;
                    // // move to the ladder
                    // q.push({next_ladder, true, prevStep + 1});
                    // visited[next_ladder] = true;
                }
                if (nxt == n2) {
                    return prevStep + 1;
                }
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    q.push({nxt, prevStep + 1});
                }
            }
        }
        
        return -1;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> b = {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}
    };
    cout << s.snakesAndLadders(b) << endl;
    return 0;
}