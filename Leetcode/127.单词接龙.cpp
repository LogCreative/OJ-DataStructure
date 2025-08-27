/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
    bool diff_one(string left, string right) {
        int l = left.length();
        bool flag = false;
        for (int i = 0; i < l; ++i) {
            if (left[i] != right[i]) {
                if (flag) {
                    return false;
                }
                flag = true;
            }
        }
        return true;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        if (auto it = find(wordList.begin(), wordList.end(), beginWord); it != wordList.end()) {
            wordList.erase(it);
        }

        int n = wordList.size();
        vector<bool> visited(n, false);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            auto [cur, depth] = q.front(); q.pop();
            for (int i = 0; i < n; ++i) {
                if (!visited[i] && diff_one(cur, wordList[i])) {
                    // cout << '(' << wordList[i] << ',' << depth + 1 << ')';
                    if (wordList[i] == endWord) {
                        return depth + 1;
                    }
                    q.push({wordList[i], depth+1});
                    visited[i] = true;
                }
            }
        }

        return 0;
    }
};
// @lc code=end

