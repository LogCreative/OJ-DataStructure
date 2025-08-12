/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
    vector<vector<int>> edges;
    vector<int> indeg;
    vector<int> ans;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);

        for (auto pre : prerequisites) {
            edges[pre[1]].push_back(pre[0]);
            ++indeg[pre[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int u = q.front(); q.pop();
            ans.push_back(u);
            vector<int> toEdges = edges[u];
            for (int target : toEdges) {
                if (--indeg[target] == 0) {
                    q.push(target);
                }
            }
        }

        if (ans.size() != numCourses) {
            return {};
        }

        return ans;
    }
};
// @lc code=end

