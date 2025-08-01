/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> positive_nums;
        vector<int> nonpositive_nums;
        for (auto num : nums) {
            if (num > 0) {
                positive_nums.push_back(num);
            } else {
                nonpositive_nums.push_back(num);
            }
        }

        sort(positive_nums.begin(), positive_nums.end(), greater<int>());
        sort(nonpositive_nums.begin(), nonpositive_nums.end()); // ,0]
    
        if (positive_nums.size() >= 3) {
            // 正数>= 3 个，一定：0 个负数，2 个绝对值最大的负数
            int maxPositive = positive_nums[0];
            int positive_prod = positive_nums[1] * positive_nums[2];
            if (nonpositive_nums.size() >= 2) {
                positive_prod = max(positive_prod, nonpositive_nums[0] * nonpositive_nums[1]);
            }
            return maxPositive * positive_prod;
        }
        if (positive_nums.size() == 2) {
            // 正数 2 个
            if (nonpositive_nums.size() == 1) {
                // 剩下一个必然是负数，但应当是绝对值最小的负数
                return positive_nums[0] * positive_nums[1] * nonpositive_nums[nonpositive_nums.size() - 1];
            }
            return positive_nums[0] * nonpositive_nums[0] * nonpositive_nums[1];
        }
        if (positive_nums.size() == 1) {
            // 正数 1 个：2个绝对值最大的负数
            return positive_nums[0] * nonpositive_nums[0] * nonpositive_nums[1];
        }
        // 正数 0 个：全是负数，但绝对值最小的负数
        return nonpositive_nums[nonpositive_nums.size() - 1] * nonpositive_nums[nonpositive_nums.size() - 2] * nonpositive_nums[nonpositive_nums.size() - 3];
    }
};
// @lc code=end

