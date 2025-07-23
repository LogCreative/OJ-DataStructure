/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return false;
        int sum = 0;
        int max_element = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            max_element = max(max_element, nums[i]);
        }
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        if (max_element > target) return false;

        // sort(nums.begin(), nums.end());

        // int left = -1, right = n;
        // int leftsum = 0, rightsum = 0;
        // while (left < right) {
        //     leftsum += nums[++left];
        //     if (leftsum == rightsum) {
        //         return true;
        //     } else if (leftsum > rightsum) {
        //         if (right - 1 <= left) return false;
        //         rightsum += nums[--right];
        //         if (leftsum == rightsum) {
        //             return true;
        //         }
        //     }
        // }
        // return false;

        // int leftsum = 0, rightsum = 0;
        // for (int i = 0; i < n; ++i) {
        //     rightsum += nums[i];
        // }
        // for (int i = 0; i < n - 1; ++i) {
        //     leftsum += nums[i];
        //     rightsum -= nums[i];
        //     if (leftsum == rightsum) {
        //         return true;
        //     }
        // }
        // return false;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        // dp[i-1][j] = true => dp[i][j + nums[i]] = true; dp[i][j] = true (j >= nums[i])
        // dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i]] , j >= nums[i]
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= target; ++j) {
                if (j >= nums[i]){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][target];
    }
};
// @lc code=end

