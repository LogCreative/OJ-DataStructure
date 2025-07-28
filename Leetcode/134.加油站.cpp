/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    // static bool cmp(const pair<int,int> &l, const pair<int,int> &r) {
    //     return l.second > r.second;
    // }

    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     int n = gas.size();
    //     vector<pair<int,int>> starts;
    //     for (int i = 0; i < n; ++i) {
    //         if (gas[i] - cost[i] >= 0) {
    //             starts.push_back({i, gas[i] - cost[i]});
    //         }
    //     }
    //     if (starts.empty()) {
    //         return -1;
    //     }
    //     sort(starts.begin(), starts.end(), cmp);
    //     for (auto it = starts.begin(); it != starts.end(); ++it) {
    //         int start = (*it).first;
    //         int cur_gas = 0;
    //         bool flag = true;
    //         for (int k = start; k < start + n; ++k) {
    //             int pos = k % n;
    //             cur_gas += gas[pos];
    //             if (cur_gas >= cost[pos]) {
    //                 cur_gas -= cost[pos];
    //             } else {
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         if (flag) {
    //             return start;
    //         }
    //     }
    //     return -1;
    // }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //假设以start为起点，若在到达i处时油量不足以到达i+1，则
        //1. 从0到i的任何一个起点j出发都无法到达i（因为在到达j站时油量必>=0）,因此尝试从i+1开始
        //2. 从0到i可行，因此若能从i+1到达尾部，那么也能绕一圈到达i（从最后一站到0站的可行性由curRest>=0保证）
        int n = gas.size();
        int start = 0;
        int total_sum = 0, cur_sum = 0;
        for (int i = 0; i < n; ++i) {
            int diff = gas[i] - cost[i];
            total_sum += diff;
            cur_sum += diff;
            if (cur_sum < 0) {
                start = i + 1;
                cur_sum = 0;
            }
        }
        if (total_sum >= 0) { // 绕一圈
            return start;
        } else {
            return -1;
        }
    }
};
// @lc code=end

