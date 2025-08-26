/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> cur_line;
        int cur_width = 0;
        for (string word : words) {
            if (cur_line.size() > 0 && cur_width + 1 + word.length() > maxWidth) {
                int line_num = cur_line.size();
                int num_space = line_num - 1;
                int space_left = maxWidth - cur_width;
                vector<int> spaces(line_num, 1);
                
                if (num_space == 0) {
                    spaces[line_num - 1] = space_left;
                } else {
                    spaces[line_num - 1] = 0;
                    int add_space = space_left / num_space;
                    for (int i = 0; i < num_space; ++i) {
                        spaces[i] += add_space;
                    }
                    int left_add = space_left % num_space;
                    if (left_add > 0) {
                        for (int l = 0; l < left_add; ++l) {
                            spaces[l] += 1;
                        }
                    }
                }
                
                string line;
                for (int j = 0; j < line_num; ++j) {
                    line += cur_line[j];
                    for (int k = 0; k < spaces[j]; ++k) {
                        line += ' ';
                    }
                }
                ans.push_back(line);

                cur_width = word.length();
                cur_line.clear();
                cur_line.push_back(word);
            } else {
                // 单词小于行长
                cur_width += (cur_line.size() == 0 ? 0 : 1) + word.length();
                cur_line.push_back(word);
            }
        }

        if (cur_line.size() > 0) {
            string line;
            line += cur_line[0];
            int line_num = cur_line.size();
            for (int j = 1; j < line_num; ++j) {
                line += ' ' + cur_line[j];
            }
            int space_right = maxWidth - cur_width;
            for (int j = 0; j < space_right; ++j) {
                line += ' ';
            }
            ans.push_back(line);
        }
        
        return ans;
    }
};
// @lc code=end

