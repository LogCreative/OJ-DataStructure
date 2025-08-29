/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

#include<iostream>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
    vector<string> next_status(string cur) {
        vector<string> status_arr;
        for (int i = 0; i < 4; ++i) {
            char num = cur[i];
            if (num == '0') {
                cur[i] = '9';
            } else {
                cur[i] = num - 1;
            }
            status_arr.push_back(cur);
            if (num == '9') {
                cur[i] = '0';
            } else {
                cur[i] = num + 1;
            }
            status_arr.push_back(cur);
            cur[i] = num;
        }
        return status_arr;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") {
            return 0;
        }

        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) {
            return -1;
        }

        int n = deadends.size();
        queue<pair<string, int>> q;
        unordered_set<string> visited = { "0000" };
        q.push({"0000", 0});
        while (!q.empty()) {
            auto [cur, step] = q.front(); q.pop();
            for (string next : next_status(cur)) {
                if (next == target) {
                    return step + 1;
                }
                if (dead.count(next) || visited.count(next)) {
                    continue;
                }
                q.push({next, step + 1});
                visited.insert(next);
            }
        }
        return -1;

        // could be improved by a-star;
    }
};
// @lc code=end

