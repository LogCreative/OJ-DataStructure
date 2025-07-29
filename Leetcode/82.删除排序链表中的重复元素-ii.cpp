/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode(INT_MIN, head);
        
        ListNode* cur = dummy;
        while(cur->next != nullptr && cur->next->next != nullptr) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while(cur->next != nullptr && cur->next->val == x) {
                    // ListNode* tmp = cur->next;
                    cur->next = cur->next->next;
                    // delete tmp;
                }
            } else {
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};
// @lc code=end

