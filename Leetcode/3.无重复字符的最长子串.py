#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        cur = set()
        left = 0
        right = 0
        n = len(s)
        ans = 0
        while right < n:
            if s[right] in cur:
                cur.remove(s[left])
                left += 1
            else:
                cur.add(s[right])
                right += 1
                ans = max(ans, len(cur))
        return ans
        
# @lc code=end

