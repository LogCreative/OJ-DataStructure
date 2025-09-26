#
# @lc app=leetcode.cn id=997 lang=python3
#
# [997] 找到小镇的法官
#

from typing import List

# @lc code=start
class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        # 寻找入度为 n-1，出度为0的
        in_degree = [0] * n
        out_degree = [0] * n
        for t in trust:
            out_degree[t[0]-1] += 1
            in_degree[t[1]-1] += 1
        for i in range(n):
            if in_degree[i] == n-1 and out_degree[i] == 0:
                return i+1
        return -1
# @lc code=end

