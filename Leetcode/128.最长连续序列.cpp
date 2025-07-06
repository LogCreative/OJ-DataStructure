/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> cnt;

        // [100,4,200,1,3,2]
        //      1       x

        for (int num : nums) {
            int prev = cnt.find(num-1) == cnt.end() ? 0 : cnt[num-1]; // 0
            int post = cnt.find(num+1) == cnt.end() ? 0 : cnt[num+1]; // 1
            if (cnt.find(num) == cnt.end()) {
                cnt[num] = prev + post + 1; // 2
                cnt[num-prev] = cnt[num]; // 2
                cnt[num+post] = cnt[num]; // cnt[4]=2 一致性问题：因为哈希表的value存的是长度，当有新数字插入时，与其相邻的数字长度也需要改变。但是我们不需要把这个连续序列全部都修改，只需要修改这个连续序列的边缘数字，因为连续序列内的数字改变没有意义，我们不会把数字插入到连续序列内 https://leetcode.cn/problems/longest-consecutive-sequence/description/comments/2436490/
            }
        }

        int ans = 0;
        for (pair<int, int> x : cnt) {
            ans = max(ans, x.second);
        }
        return ans;
    }
};
// @lc code=end

