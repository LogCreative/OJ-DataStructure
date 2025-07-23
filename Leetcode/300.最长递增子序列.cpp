/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> f(n, 0); // 以 ni 结尾的最长递增子序列
    //     int ans = 1;
    //     f[0] = 1;
    //     // f(i) = maxf(j) + 1, a_j<a_i
    //     for (int i = 1; i < n; ++i) {
    //         int maxj = 0;
    //         for (int j = 0; j < i; ++j) {
    //             if (f[j] > maxj && nums[j] < nums[i]) {
    //                 maxj = f[j];
    //             }
    //         }
    //         f[i] = maxj + 1;
    //         ans = max(ans, f[i]);
    //     }
    //     return ans;
    // }

    int lengthOfLIS(vector<int>& nums) {
        // https://writings.sh/post/longest-increasing-subsequence-revisited
        int len = 1, n = nums.size();
        if (n == 0) return 0;
        vector<int> d(n+1,0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
            } else {
                int l = 1, r = len, pos = 0;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};
// @lc code=end

