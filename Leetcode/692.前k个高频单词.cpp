/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

#include<iostream>
#include<unordered_map>
using namespace std;

// @lc code=start
struct cmp {
    bool operator()(pair<int, string> l, pair<int, string> r) {
        if (l.first == r.first) {
            return l.second > r.second;
        }
        return l.first < r.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wc;
        for (string word : words) {
            wc[word]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for (auto [w, c] : wc) {
            pq.push({c, w});
        }
        vector<string> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(pq.top().second); pq.pop();
        }
        return ans;
    }
};
// @lc code=end

