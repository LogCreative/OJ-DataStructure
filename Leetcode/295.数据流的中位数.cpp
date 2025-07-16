/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

#include<iostream>
using namespace std;

// @lc code=start
// class MedianFinder {
//     priority_queue<int> pq;
// public:
//     MedianFinder() {

//     }
    
//     void addNum(int num) {
//         pq.push(num);
//     }
    
//     double findMedian() {
//         int n = pq.size();
//         priority_queue<int> tmp_pq = pq;
//         if (n % 2 == 1) {
//             int mid = (n - 1) / 2;
//             for (int i = 0; i < mid; ++i) {
//                 tmp_pq.pop();
//             }
//             return tmp_pq.top();
//         } else {
//             int mid = n / 2 - 1;
//             for (int i = 0; i < mid; ++i) {
//                 tmp_pq.pop();
//             }
//             double ans = tmp_pq.top();
//             tmp_pq.pop();
//             ans = (ans + tmp_pq.top()) / 2.0;
//             return ans;
//         }
//     }
// };


class MedianFinder {
    priority_queue<int, vector<int>, less<int>> pqMin;
    priority_queue<int, vector<int>, greater<int>> pqMax;
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (pqMin.empty() || num <= pqMin.top()) {
            pqMin.push(num);
            if (pqMax.size() + 1 < pqMin.size()) {
                pqMax.push(pqMin.top());
                pqMin.pop();
            }
        } else {
            pqMax.push(num);
            if (pqMin.size() < pqMax.size()) {
                pqMin.push(pqMax.top());
                pqMax.pop();
            }
        }
    }
    
    double findMedian() {
        if (pqMin.size() > pqMax.size()) {
            return pqMin.top();
        }
        return (pqMin.top() + pqMax.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

