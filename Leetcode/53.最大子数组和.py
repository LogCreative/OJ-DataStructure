#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子数组和
#

from typing import List

# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        f = [0] * n
        f[0] = nums[0]
        for i in range(1, n):
            # f[i-1] + nums[i-1] <= nums[i-1]
            f[i] = f[i-1] + nums[i] if f[i-1]>0 else nums[i]
        return max(f)
# @lc code=end

