#
# @lc app=leetcode.cn id=290 lang=python3
#
# [290] 单词规律
#

# @lc code=start
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s_words = s.split()
        p_s_map = {}
        s_p_map = {}
        if len(pattern) != len(s_words):
            return False
        n = len(pattern)
        for i in range(n):
            p_c = pattern[i]
            s_w = s_words[i]
            if p_c in p_s_map and s_w != p_s_map[p_c]:
                return False
            if s_w in s_p_map and p_c != s_p_map[s_w]:
                return False
            p_s_map[p_c] = s_w
            s_p_map[s_w] = p_c
        return True
# @lc code=end

