/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

#include<iostream>
using namespace std;

// @lc code=start

class UnionFind {
    vector<int> parent;
public:
    UnionFind() {
        parent = vector<int>();
        for (int i = 0; i < 26; ++i) {
            parent.push_back(i);
        }
    }

    int find(int index) {
        if (index == parent[index]) {
            return index;
        }
        parent[index] = find(parent[index]);
        return parent[index];
    }

    void unite(int index1, int index2) {
        parent[find(index1)] = find(index2);
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf;
        for (string eq : equations) {
            if (eq[1] == '=') {
                uf.unite(eq[0] - 'a', eq[3] - 'a');
            }
        }
        for (string eq : equations) {
            if (eq[1] == '!') {
                int left_index = uf.find(eq[0] - 'a');
                int right_index = uf.find(eq[3] - 'a');
                if (left_index == right_index) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

