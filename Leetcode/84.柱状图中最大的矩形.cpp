/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 超时
        int n = heights.size();
        int max_area = 0, height, width;

        // for (int i = 0; i < n; ++i) {
        //     height = heights[i];
        //     width = 1;
        //     if (height * width > max_area) {
        //         max_area = height * width;
        //     }
        //     for (int j = i + 1; j < n; ++j) {
        //         ++width;
        //         if (heights[j] < height) {
        //             height = heights[j];
        //         }
        //         if (height * width > max_area) {
        //             max_area = height * width;
        //         }
        //     }
        // }
        // return max_area;

        // 木桶效应，考虑最底层。
        stack<int> height_stack;
        for (int i = 0; i <= n; ++i) {
            int curHeight = (i == n ? 0 : heights[i]);
            
            while(!height_stack.empty() && curHeight < heights[height_stack.top()]) {
                int height = heights[height_stack.top()]; 
                height_stack.pop();
                int width = height_stack.empty() ? i : i - height_stack.top() - 1;
                max_area = max(max_area, height * width);
            }

            height_stack.push(i);
        }
        return max_area;
    }
};
// @lc code=end

