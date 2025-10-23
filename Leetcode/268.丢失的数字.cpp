/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n+1, false);
        for (int num : nums) {
            visited[num] = true;
        }
        for (int i = 0; i <= n; ++i) {
            if (!visited[i]) {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end

