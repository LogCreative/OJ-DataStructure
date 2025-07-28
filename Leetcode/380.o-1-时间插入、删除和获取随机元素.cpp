/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

#include<iostream>
using namespace std;

// @lc code=start
class RandomizedSet {
    vector<int> nums;
    unordered_map<int,int> indices;
public:
    RandomizedSet() {
        // srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if (indices.find(val) != indices.end()) {
            return false;
        }
        int pos = nums.size();
        nums.push_back(val);
        indices[val] = pos;
        return true;
    }
    
    bool remove(int val) {
        if (indices.find(val) == indices.end()) {
            return false;
        }
        int pos = indices[val];
        int last = nums.back();
        nums.pop_back();
        nums[pos] = last;
        indices[last] = pos;
        indices.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

