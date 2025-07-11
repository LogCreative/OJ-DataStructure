/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
class Solution {
public:
    unordered_map<long long, int> prefixCnt;

    int dfs(TreeNode* root, int targetSum, long long prefixSum) {
        if (root == nullptr) return 0;
        prefixSum += root->val;
        int pathCnt = prefixCnt[prefixSum - targetSum]; // 560.
        prefixCnt[prefixSum] += 1;
        pathCnt += dfs(root->left, targetSum, prefixSum) + dfs(root->right, targetSum, prefixSum);
        prefixCnt[prefixSum] -= 1; // 该路径不再可用
        return pathCnt;
    }

    int pathSum(TreeNode* root, int targetSum) {
        prefixCnt[0] = 1;
        return dfs(root, targetSum, 0);
    }
};
// @lc code=end

