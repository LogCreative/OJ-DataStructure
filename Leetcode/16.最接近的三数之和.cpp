/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // min abs(nums[i] + nums[j] + nums[k] - target)
        int n = nums.size();
        if (n == 3) {
            return (nums[0] + nums[1] + nums[2]);
        }

        sort(nums.begin(), nums.end());

        int ans = nums[0] + nums[1] + nums[n-1];

        for (int i = 0; i < n - 2; ++i) {
            // 固定 a
            int a = i;
            int b = i + 1;
            int c = n - 1;
            while (b < c) {
                int three_sum = nums[a] + nums[b] + nums[c];
                ans = abs(ans - target) > abs(three_sum - target) ? three_sum : ans;
                // cout << ans << ' ';
                if (three_sum > target) {
                    --c;
                } else if (three_sum == target) {
                    return ans;
                } else {
                    ++b;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

