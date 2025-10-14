#
# @lc app=leetcode.cn id=215 lang=python3
#
# [215] 数组中的第K个最大元素
#

from typing import List
from random import randint

# @lc code=start
class Solution:
    def partition(self, nums: List[int], left: int, right: int) -> int:
        i = randint(left, right)
        pivot = nums[i]
        nums[i], nums[left] = nums[left], nums[i]

        i = left + 1
        j = right
        while True:
            while i <= j and nums[i] < pivot:
                i += 1
            while i <= j and nums[j] > pivot:
                j -= 1
            if i >= j: break
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1
        nums[left], nums[j] = nums[j], nums[left]
        return j

    def findKthLargest(self, nums: List[int], k: int) -> int:
        n = len(nums)
        target_index = n - k
        left, right = 0, n - 1
        while True:
            i = self.partition(nums, left, right)
            if i == target_index:
                return nums[i]
            if i > target_index:
                right = i - 1
            if i < target_index:
                left = i + 1

# @lc code=end

