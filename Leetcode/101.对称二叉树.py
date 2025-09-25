#
# @lc app=leetcode.cn id=101 lang=python3
#
# [101] 对称二叉树
#

from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def check(self, left, right):
        if (left == None and right == None):
            return True
        if (left == None or right == None):
            return False
        return left.val == right.val and self.check(left.right, right.left) and self.check(left.left, right.right)
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.check(root.left, root.right)
# @lc code=end

