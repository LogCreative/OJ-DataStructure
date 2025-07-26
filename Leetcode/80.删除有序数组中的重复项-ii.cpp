/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return n;
        }
        int slow = 2, fast = 2;
        //.     f
        // [1 2 2 3]
        //      s 
        while(fast < n) {
            if (nums[fast] != nums[slow-2]) { // 26 使用 slow-1 也能过
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
// @lc code=end

