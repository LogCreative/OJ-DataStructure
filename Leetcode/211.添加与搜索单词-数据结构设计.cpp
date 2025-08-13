/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

#include<iostream>
using namespace std;

// @lc code=start
class WordDictionary {
    vector<WordDictionary*> children;
    bool isEnd;
public:
    WordDictionary() {
        children = vector<WordDictionary*>(26);
        isEnd = false;
    }
    
    void addWord(string word) {
        WordDictionary* cur = this;
        for (auto ch : word) {
            int ch_id = ch - 'a';
            if (cur->children[ch_id] == nullptr) {
                cur->children[ch_id] = new WordDictionary();
            }
            cur = cur->children[ch_id];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        if (word.length() == 0) {
            return isEnd;
        }
        WordDictionary* cur = this;
        char first_char = word[0];
        string postfix = word.substr(1,word.length()-1);
        if (word[0] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (cur->children[i] != nullptr && cur->children[i]->search(postfix)) {
                    return true;
                }
            }
            return false;
        } else {
            if (cur->children[first_char - 'a'] == nullptr) {
                return false;
            }
            return cur->children[first_char - 'a']->search(postfix);
        }
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

