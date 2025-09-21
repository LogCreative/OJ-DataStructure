#
# @lc app=leetcode.cn id=91 lang=python3
#
# [91] 解码方法
#

# @lc code=start
class Solution:
    def numDecodings(self, s: str) -> int:
        # CHARSET = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        n = len(s)
        f = [0] * (n+1)
        f[0] = 1
        for i in range(1, n+1):
            if s[i-1] != '0':
                f[i] += f[i-1]
            if i-2 >= 0 and s[i-2] != '0' and int(s[i-2]) * 10 + int(s[i-1]) <= 26:
                f[i] += f[i-2]
        return f[n]
# @lc code=end

