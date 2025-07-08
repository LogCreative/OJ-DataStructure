/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
 */

#include<iostream>
#include<stack>
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
    int ans;

    void midOrder(TreeNode* root, int &k) {
        if (root->left != nullptr) midOrder(root->left, k);
        if (--k == 0) {
            ans = root->val;
            return;
        }
        if (root->right != nullptr) midOrder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        midOrder(root, k);
        return ans;
    }
};
// @lc code=end

