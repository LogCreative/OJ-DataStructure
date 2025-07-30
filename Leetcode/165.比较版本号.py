#
# @lc app=leetcode.cn id=165 lang=python3
#
# [165] 比较版本号
#

# @lc code=start
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        version1_parts = list(map(int, version1.split('.')))
        version2_parts = list(map(int, version2.split('.')))
        if len(version1_parts) < len(version2_parts):
            version1_parts.extend([0] * (len(version2_parts) - len(version1_parts)))
        else:
            version2_parts.extend([0] * (len(version1_parts) - len(version2_parts)))
        for i, v1 in enumerate(version1_parts):
            if v1 < version2_parts[i]:
                return -1
            elif v1 > version2_parts[i]:
                return 1
        return 0
# @lc code=end

