/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

#include<iostream>
#include<set>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> split_start;
        vector<set<char>> visited;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            int visited_index = -1;
            for (int j = 0; j < visited.size(); ++j) {
                if (visited[j].find(c) != visited[j].end()) {
                    visited_index = j;
                    break;
                }
            }
            if (visited_index == -1) {
                split_start.push_back(i);
                visited.push_back(set<char>({c})); 
            } else {
                // 把前序相连
                for (int k = split_start.size() - 1; k >= visited_index + 1; --k) {
                    split_start.pop_back();
                    for (int num : visited[k]) {
                        visited[visited_index].insert(num);
                    }
                    visited.pop_back();
                }
            }
        }
        vector<int> ans;
        int prev_start = -1;
        for (int start : split_start) {
            cout << start << " ";
            if (prev_start == -1) {
                prev_start = start;
                continue;
            }
            ans.push_back(start - prev_start);
            prev_start = start;
        }
        ans.push_back(n - prev_start);
        return ans;
    }
};
// @lc code=end

