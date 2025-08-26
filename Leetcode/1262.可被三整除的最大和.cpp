/*
 * @lc app=leetcode.cn id=1262 lang=cpp
 *
 * [1262] 可被三整除的最大和
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> rem;
        for (int i = 0; i < 3; ++i) {
            rem[i] = vector<int>();
        }
        for (int num : nums) {
            rem[num % 3].push_back(num);
        }
        sort(rem[1].begin(), rem[1].end(), greater<int>());
        sort(rem[2].begin(), rem[2].end(), greater<int>());
        
        // 按丢弃计算
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }

        int remove = INT_MAX;
        if (sum % 3 == 0) {
            remove = 0;
        } else if (sum % 3 == 1) {
            if (rem[1].size() >= 1)
                remove = min(remove, rem[1].end()[-1]);
            if (rem[2].size() >= 2)
                remove = min(remove, rem[2].end()[-2] + rem[2].end()[-1]);
        } else {
            if (rem[1].size() >= 2)
                remove = min(remove, rem[1].end()[-2] + rem[1].end()[-1]);
            if (rem[2].size() >= 1)
                remove = min(remove, rem[2].end()[-1]);
        }

        return sum - remove;
    }
};
// @lc code=end

