/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int dfs(TreeNode* root, int prev_num) {
        if (root == nullptr) {
            return 0;
        }

        int cur_sum = prev_num * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            return cur_sum;
        } else {
            return dfs(root->left, cur_sum) + dfs(root->right, cur_sum);
        }
    }

public:
    int sumNumbers(TreeNode* root) {
        //.    1
        //.   / \
        //.  5   1
        //.       \
        //.        6

        return dfs(root, 0);
        // 15 + 116 = 

        // vector<int> num_stack;
        // stack<TreeNode*> node_stack;
        // int ans = 0;
        // if (root == nullptr) {
        //     return ans;
        // }
        // node_stack.push(root);
        // TreeNode* top_node;
        // while (!node_stack.empty()) {
        //     top_node = node_stack.top();
        //     node_stack.pop();
        //     num_stack.push_back(top_node->val);
        //     if (top_node->left == nullptr && top_node->right == nullptr) {
        //         int cur = 0;
        //         for (int num : num_stack) {
        //             cout << num << ' ';
        //             cur = cur * 10 + num;
        //         }
        //         cout << endl;
        //         ans += cur;
        //         num_stack.pop_back();
        //     } else {
        //         if (top_node->left) node_stack.push(top_node->left);
        //         if (top_node->right) node_stack.push(top_node->right);
        //     }
        // }
        // return ans;
    }
};
// @lc code=end

