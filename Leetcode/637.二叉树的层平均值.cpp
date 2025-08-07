/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<pair<TreeNode*, int>> tra_queue;
        tra_queue.push({root, 0});
        int prev_depth = 0;
        long long cur_sum = 0;
        int cur_num = 0;
        vector<double> ans;
        while (!tra_queue.empty()) {
            auto ele = tra_queue.front();
            tra_queue.pop();

            TreeNode* cur_node = ele.first;
            int cur_depth = ele.second;
            if (cur_node->left) tra_queue.push({cur_node->left, cur_depth + 1});
            if (cur_node->right) tra_queue.push({cur_node->right, cur_depth + 1});

            if (cur_depth > prev_depth) {
                ans.push_back((double)cur_sum / cur_num);
                cur_sum = cur_node->val;
                cur_num = 1;
                prev_depth = cur_depth;
            } else {
                cur_sum += cur_node->val;
                cur_num += 1;
            }
        }
        if (cur_num > 0) {
            ans.push_back((double)cur_sum / cur_num);
        }

        return ans;
    }
};
// @lc code=end

