/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        // vector<int> right_candies(n);
        // for (int i = n - 1; i >= 0; --i) {
        //     if (i < n - 1 && ratings[i] > ratings[i+1]) {
        //         right_candies[i] = right_candies[i+1] + 1;
        //     } else {
        //         right_candies[i] = 1;
        //     }
        // }
        
        // vector<int> left_candies(n);
        // for (int i = 0; i < n; ++i) {
        //     if (i > 0 && ratings[i] > ratings[i-1]) {
        //         left_candies[i] = left_candies[i-1] + 1;
        //     } else {
        //         left_candies[i] = 1;
        //     }
        // }

        // int ans = 0;
        // for (int i = 0; i < n; ++i) {
        //     ans += max(left_candies[i], right_candies[i]);
        // }
        // return ans;

        // 另一种解法：

        // 我们无需显式地额外分配糖果，只需要记录当前的递减序列长度，即可知道需要额外分配的糖果数量。

        // 同时注意当当前的递减序列长度和上一个递增序列等长时，需要把最近的递增序列的最后一个同学也并进递减序列中。

        int ans = 1;
        int inc = 1, dec = 0, prev = 1;
        for (int i = 1; i < n; ++i) {
            if (ratings[i] >= ratings[i-1]) {
                dec = 0;
                prev = ratings[i] == ratings[i-1] ? 1 : prev + 1;
                ans += prev;
                inc = prev;
            } else {
                dec++;
                if (inc == dec) {
                    dec++;
                }
                ans += dec;
                prev = 1;
            }
        }
        return ans;
    }
};
// @lc code=end

