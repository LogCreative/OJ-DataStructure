/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    // int findDuplicate(vector<int>& nums) {
    //     // 利用下标的性质
    //     int n = nums.size();
    //     int l = 1, r = n - 1, ans = -1;
    //     int mid, cnt;
    //     while (l <= r) {
    //         mid = (l + r) / 2;
    //         cnt = 0;
    //         for (int i = 0; i < n; ++i) {
    //             cnt += nums[i] <= mid;
    //         }
    //         if (cnt <= mid) {
    //             l = mid + 1;
    //         } else {
    //             r = mid - 1;
    //             ans = mid;
    //         }
    //     }
    //     return ans;
    // }

    int findDuplicate(vector<int>& nums) {
        // 利用环的性质
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// @lc code=end

