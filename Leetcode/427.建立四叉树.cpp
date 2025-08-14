/*
 * @lc app=leetcode.cn id=427 lang=cpp
 *
 * [427] 建立四叉树
 */

#include<iostream>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

// @lc code=start

class Solution {
    bool isSame(vector<vector<int>>& grid, int top, int left, int n) {
        int prev = grid[top][left];
        for (int i = top; i < top + n; ++i) {
            for (int j = left; j < left + n; ++j) {
                if (grid[i][j] != prev) {
                    return false;
                }
            }
        }
        return true;
    }

    Node* construct_node(vector<vector<int>>& grid, int top, int left, int n) {
        if (n == 1) {
            return new Node(grid[top][left], true);
        }
        if (isSame(grid, top, left, n)) {
            return new Node(grid[top][left], true);
        }
        int m = n / 2;
        Node* topLeft = construct_node(grid, top, left, m);
        Node* topRight = construct_node(grid, top, left + m, m);
        Node* bottomLeft = construct_node(grid, top + m, left, m);
        Node* bottomRight = construct_node(grid, top + m, left + m, m);
        return new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return construct_node(grid, 0, 0, n);
    }
};
// @lc code=end

