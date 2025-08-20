/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
    double quickMul(double x, long long n) {
        // if (n == 0) {
        //     return 1.0;
        // }
        // double y = quickMul(x, n / 2);
        // return n % 2 == 0 ? y * y : y * y * x;

        // 也可以将 n 用二进制表示，然后再相乘
        double ans = 1.0;
        double x_con = x;
        while (n > 0) {
            if (n % 2) {
                ans *= x_con;
            }
            x_con *= x_con;
            n /= 2;
        }
        return ans;
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        return n >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
// @lc code=end

