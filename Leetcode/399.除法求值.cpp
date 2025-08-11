/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

#include<iostream>
using namespace std;

// @lc code=start
class UnionFind {
    unordered_map<string, string> parents;
    unordered_map<string, double> weights;
public:
    UnionFind() {
    }

    string find(string var) {
        if (!parents.count(var)) {
            parents[var] = var;
            weights[var] = 1;
        }
        if (var != parents[var]) {
            string father = parents[var];
            parents[var] = find(parents[var]);
            weights[var] = weights[father] * weights[var];
        }
        return parents[var];
    }

    void unite(string var1, string var2, double weight) {
        string father1 = find(var1);
        string father2 = find(var2);
        if (father1 == father2) {
            return ;
        }
        parents[father1] = father2;
        weights[father1] = weights[var2] * weight / weights[var1];
        father1 = find(var1);
    }

    double get_result(string var1, string var2) {
        if (!parents.count(var1) || !parents.count(var2)) {
            return -1;
        }
        string father1 = find(var1);
        string father2 = find(var2);
        if (father1 == father2) {
            return weights[var1] / weights[var2];
        } else {
            return -1;
        }
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        UnionFind uf;
        int n = equations.size();
        for (int i = 0; i < n; ++i) {
            uf.unite(equations[i][0], equations[i][1], values[i]);
        }

        vector<double> ans;
        for (vector<string> query : queries) {
            ans.push_back(uf.get_result(query[0], query[1]));
        }
        return ans;
    }
};
// @lc code=end

