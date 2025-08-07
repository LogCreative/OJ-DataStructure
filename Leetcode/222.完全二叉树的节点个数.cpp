/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int height_left = 0;
        TreeNode* left_most = root;
        while (left_most->left) {
            ++height_left;
            left_most = left_most->left;
        }
        int height_right = 0;
        TreeNode* right_most = root;
        while (right_most->right) {
            ++height_right;
            right_most = right_most->right;
        }
        if (height_left == height_right) {
            return (int)pow(2, height_left + 1) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
// @lc code=end

