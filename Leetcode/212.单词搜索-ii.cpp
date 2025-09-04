/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

// @lc code=start
struct TrieNode {
    string word;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        word = "";
    }
};

void insertTrie(TrieNode* root, string word) {
    TrieNode* node = root;
    for (char c : word) {
        if (node->children.count(c) == 0) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->word = word;
}

class Solution {
    // string format_pos(pair<int, int> pos) {
    //     return to_string(pos.first) + ',' + to_string(pos.second);
    // }

    int m, n;
    set<string> ans;

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root) {
        char ch = board[i][j];
        if (root == nullptr || root->children.count(ch) == 0) {
            return;
        }
        TrieNode* next_node = root->children[ch];
        if (next_node->word.size() > 0) {
            ans.insert(next_node->word);
            next_node->word = ""; // 为了缓解这种情况，我们可以将匹配到的单词从前缀树中移除，来避免重复寻找相同的单词。因为这种方法可以保证每个单词只能被匹配一次；所以我们也不需要再对结果集去重了。
        }
        if (!next_node->children.empty()) { //
            board[i][j] = '#';

            vector<pair<int,int>> next_status;
            if (i > 0)   next_status.push_back({i-1,j});
            if (i < m-1) next_status.push_back({i+1,j});
            if (j > 0)   next_status.push_back({i,j-1});
            if (j < n-1) next_status.push_back({i,j+1});
            for (auto next : next_status) {
                if (board[next.first][next.second] != '#') {
                    dfs(board, next.first, next.second, next_node);
                }
            }

            board[i][j] = ch;
        }
        if (next_node->children.empty()) {
            root->children.erase(ch); //
        }
        
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        // unordered_map<char, vector<pair<int, int>>> c_map;
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         c_map[board[i][j]].push_back({i, j});
        //     }
        // }

        // // a b c
        // // a e d
        // // a f g

        // vector<string> ans;
        // for (string word : words) {
        //     if (c_map.count(word[0])) {
        //         int l = word.length();
        //         if (l == 1) {
        //             ans.push_back(word);
        //             continue;
        //         }
        //         bool flag = false;
        //         for (pair<int,int> pos : c_map[word[0]]) {
        //             queue<tuple<int, int, int>> q;
        //             unordered_set<string> visited;
        //             q.push({pos.first, pos.second, 0});
        //             string formatted_pos = format_pos(pos);
        //             visited.insert(formatted_pos); // 有问题，需要回溯
        //             while (!q.empty()) {
        //                 auto [x, y, cur_index] = q.front(); q.pop();
        //                 if (cur_index == l - 1) {
        //                     ans.push_back(word);
        //                     flag = true;
        //                     break;
        //                 }
        //                 vector<pair<int,int>> next_status;
        //                 if (x > 0)   next_status.push_back({x-1,y});
        //                 if (x < m-1) next_status.push_back({x+1,y});
        //                 if (y > 0)   next_status.push_back({x,y-1});
        //                 if (y < n-1) next_status.push_back({x,y+1});
        //                 bool cur_flag = false;
        //                 for (auto next : next_status) {
        //                     if (!visited.count(format_pos(next)) && board[next.first][next.second]==word[cur_index + 1]) {
        //                         // cout << format_pos(next) << ',' << cur_index + 1 << ' ';
        //                         q.push({next.first, next.second, cur_index + 1});
        //                         visited.insert(format_pos(next));
        //                         cur_flag = true;
        //                     }
        //                 }
        //                 if (!flag) {
        //                     visited.erase(format_pos({x,y}));
        //                 }
        //                 cout << '\n';
        //             }
        //             if (flag) {
        //                 break;
        //             }
        //         }
        //     }
        // }

        TrieNode* root = new TrieNode();
        for (string word : words) {
            insertTrie(root, word);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, root);
            }
        }
        vector<string> res(ans.begin(), ans.end());
        return res;
    }
};
// @lc code=end

