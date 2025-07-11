/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

#include<iostream>
using namespace std;

// @lc code=start
class Trie {
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* cur = this;
        for (auto ch : prefix) {
            if (cur->children[ch - 'a'] == nullptr) {
                return nullptr;
            }
            cur = cur->children[ch - 'a'];
        }
        return cur;
    }

public:
    Trie() {
        children = vector<Trie*>(26);
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* cur = this;
        for (auto ch : word) {
            int ch_id = ch - 'a';
            if (cur->children[ch_id] == nullptr) {
                cur->children[ch_id] = new Trie();
            }
            cur = cur->children[ch_id];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = searchPrefix(word);
        return node != nullptr && node->isEnd == true;
    }
    
    bool startsWith(string prefix) {
        Trie* node = searchPrefix(prefix);
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

