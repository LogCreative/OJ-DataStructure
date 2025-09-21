/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1;
        int m = nums1.size();
        for (int i = 0; i < m; ++i) {
            map1[nums1[i]] = i;
        }

        int n = nums2.size();
        vector<int> next_biggest(n, -1);
        stack<pair<int, int>> stk;
        for (int i = 0; i < n; ++i) {
            int num = nums2[i];
            while (!stk.empty() && num > stk.top().first) {
                int j = stk.top().second; stk.pop();
                next_biggest[j] = num;
            }
            stk.push({num, i});
        }

        vector<int> ans(m, -1);
        for (int i = 0; i < n; ++i){
            int num = nums2[i];
            if (map1.find(num) != map1.end()) {
                ans[map1[num]] = next_biggest[i];
            }
        }
        return ans;

        // 从右边开始会更容易，可以不存序号
        // int n = nums2.size();
        // unordered_map<int, int> hm;
        // stack<int> stk;
        // for (int i = n - 1; i >= 0; --i) {
        //     int num = nums2[i];
        //     while (!stk.empty() && num >= stk.top()) {
        //         stk.pop();
        //     }
        //     hm[num] = stk.empty() ? -1 : stk.top();
        //     stk.push(num);
        // }

        // int m = nums1.size();
        // vector<int> ans(m, -1);
        // for (int i = 0; i < m; ++i) {
        //     ans[i] = hm[nums1[i]];
        // }
        // return ans;
    }
};
// @lc code=end

