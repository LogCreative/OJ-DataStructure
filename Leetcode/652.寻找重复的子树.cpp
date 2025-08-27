/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
 */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
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
    unordered_map<string, TreeNode*> seen;
    unordered_set<TreeNode*> ans;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return {ans.begin(), ans.end()};
    }

    string dfs(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        string serial = to_string(root->val) + '(' + dfs(root->left) + ')' + '(' + dfs(root->right) + ')';
        // 也可以用哈希三元组表示，使用cpp比较麻烦。
        auto it = seen.find(serial);
        if (it != seen.end()) {
            ans.insert(it->second);
        } else {
            seen[serial] = root;
        }
        return serial;
    }
};
// @lc code=end

