#
# @lc app=leetcode.cn id=279 lang=python3
#
# [279] 完全平方数
#

import math

# @lc code=start
class Solution:
    def numSquares(self, n: int) -> int:
        f = [0] * (n+1)
        for i in range(1, n+1):
            cur = math.inf
            for j in range(1, math.ceil(math.sqrt(i)) + 1):
                if j * j > i: continue
                cur = min(cur, f[i-j*j])
            f[i] = cur + 1
        return f[n]
# @lc code=end

