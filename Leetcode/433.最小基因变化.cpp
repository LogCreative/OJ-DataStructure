/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

#include<iostream>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
    int diffStr(string left, string right) {
        int diff = 0;
        for (int i = 0; i < left.length(); ++i) {
            if (left[i] != right[i]) {
                ++diff;
            }
        }
        return diff;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q;
        unordered_set<string> unvisited;
        for (string b : bank) {
            if (b != startGene) {
                unvisited.insert(b);
            }
        }
        q.push({startGene, 0});

        while(!q.empty()) {
            auto [cur, prevStep] = q.front(); q.pop();
            vector<string> next_strings;
            for (string u : unvisited) {
                if (diffStr(cur, u) == 1) {
                    if (u == endGene) {
                        return prevStep + 1;
                    }
                    next_strings.push_back(u);
                }
            }
            for (string n : next_strings) {
                unvisited.erase(n);
                q.push({n, prevStep + 1});
            }
        }

        return -1;
    }
};
// @lc code=end

