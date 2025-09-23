#
# @lc app=leetcode.cn id=200 lang=python3
#
# [200] 岛屿数量
#

from typing import List

# @lc code=start
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])

        def dfs(r, c):
            grid[r][c] = '0'
            for x, y in [(r-1,c),(r+1,c),(r,c-1),(r,c+1)]:
                if x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == '1':
                    dfs(x,y)
        
        ans = 0
        for r in range(m):
            for c in range(n):
                if grid[r][c] == '1':
                    ans += 1
                    dfs(r, c)
        
        return ans
# @lc code=end

