/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dirs;
        string cur_dir;
        path += "/";
        for (char c : path) {
            if (c == '/') {
                if (cur_dir == "") {
                    continue;
                } else if (cur_dir == ".") {
                    cur_dir = "";
                    continue;
                } else if (cur_dir == "..") {
                    if (!dirs.empty())
                        dirs.pop();
                    cur_dir = "";
                } else {
                    dirs.push(cur_dir);
                    cur_dir = "";
                }
            } else {
                cur_dir += c;
            }
        }
        string dir;
        string ans;
        if (dirs.empty()) {
            return "/";
        }
        while (!dirs.empty()) {
            dir = dirs.top(); dirs.pop();
            ans = "/" + dir + ans;
        }
        return ans;
    }
};
// @lc code=end

