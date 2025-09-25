#
# @lc app=leetcode.cn id=92 lang=python3
#
# [92] 反转链表 II
#

from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# @lc code=start
# Definition for singly-linked list.

class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:

        def reverse(node):
            prevv = None
            curr = node
            while curr:
                tmp = curr.next
                curr.next = prevv
                prevv = curr
                curr = tmp

        dummyHead = ListNode()
        dummyHead.next = head

        prev = dummyHead
        for _ in range(left - 1):
            prev = prev.next
        left_node = prev.next

        right_node = prev
        for _ in range(right - left + 1):
            right_node = right_node.next

        prev.next = None
        after_node = right_node.next
        right_node.next = None

        reverse(left_node)
        prev.next = right_node
        left_node.next = after_node

        return dummyHead.next

# @lc code=end

