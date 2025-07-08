/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

#include<iostream>
using namespace std;

#include<queue>

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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;
        if (root == nullptr) return ans;

       queue<pair<TreeNode*, int>> levelOrder;
       levelOrder.push({root, 0});

       int cur_depth = 0;
       int prev = root->val;

       while(!levelOrder.empty()) {
         auto cur = levelOrder.front(); levelOrder.pop();
         TreeNode* curNode = cur.first;
         int depth = cur.second;
        //  cout << curNode->val << " " << depth << " ";
         if (depth > cur_depth) { ans.push_back(prev); cur_depth = depth; }
         prev = curNode->val;
         if (curNode->left != nullptr) levelOrder.push({curNode->left, depth + 1});
         if (curNode->right != nullptr) levelOrder.push({curNode->right, depth + 1});
       }
       ans.push_back(prev);
       return ans;
    }
};
// @lc code=end

