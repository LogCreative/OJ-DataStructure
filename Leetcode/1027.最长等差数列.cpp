/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int max_ele = *max_element(nums.begin(), nums.end());
        int min_ele = *min_element(nums.begin(), nums.end());
        int diff = max_ele - min_ele;
        int ans = 1;
        for (int d = -diff; d <= diff; ++d) {
            // unordered_map<int, int> f;
            // for (int num : nums) {
            //     if (num - d <= max_ele && num - d >= min_ele && f.count(num - d) > 0) {
            //         f[num] = max(f.count(num) > 0 ? f[num] : -1, f[num - d] + 1);
            //         ans = max(ans, f[num]);
            //     }
            //     f[num] = max(f.count(num) > 0 ? f[num] : -1, 1);
            // }

            // space friendly ? bucket size!
            vector<int> f(max_ele + 1, -1);
            for (int num : nums) {
                if (num - d <= max_ele && num - d >= min_ele && f[num - d] != -1) {
                    f[num] = max(f[num], f[num - d] + 1);
                    ans = max(ans, f[num]);
                }
                f[num] = max(f[num], 1);
            }
        }
        return ans;
    }
};
// @lc code=end

