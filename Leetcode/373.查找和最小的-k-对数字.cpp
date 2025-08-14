/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<vector<int>> ans;
        int m = nums1.size(), n = nums2.size();
        
        priority_queue<tuple<int, int, int>> pq;
        for (int i = 0; i < m; ++i) {
            pq.push({-nums1[i]-nums2[0], i, 0});
        }

        while(ans.size() < k) {
            auto [_, i, j] = pq.top(); pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if (j + 1 < n) {
                pq.push({-nums1[i]-nums2[j+1], i, j+1});
            }
        }

        return ans;

        // wa
        // ans.push_back({nums1[i], nums2[j]});
        // --k;
        // // [x o] [x o]
        // // [x x] [x o]
        // // [x o] [x x]
        // while (k>0) {
        //     if (i + 1 < m && j + 1 < n) {
        //         if (nums1[i+1] + nums2[j] <= nums1[i] + nums2[j+1]) {
        //             ans.push_back({nums1[i+1], nums2[j]});
        //             ++i;
        //         } else {
        //             ans.push_back({nums1[i], nums2[j+1]});
        //             ++j;
        //         }
        //     } else if (i + 1 >= m && j + 1 < n) {
        //         ans.push_back({nums1[i], nums2[j+1]});
        //         ++j;
        //     } else if (i + 1 < m && j + 1 >= n) {
        //         ans.push_back({nums1[i+1], nums2[j]});
        //         ++i;
        //     } else {
        //         break;
        //     }
        //     --k;
        // }
        // return ans;
    }
};
// @lc code=end

