/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;

        ListNode dummyHead = ListNode(INT_MIN, head);

        ListNode* slow = &dummyHead;
        ListNode* fast = (&dummyHead)->next;
        while (fast && fast->val < x) {
            slow = slow->next;
            fast = fast->next;
        }
        if (!fast) return head;
        ListNode* split_prev = slow;
        ListNode* split = fast;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            while (fast && fast->val < x) {
                ListNode* next_fast = fast ? fast->next : nullptr;
                split_prev->next = fast;
                fast->next = split;
                slow->next = next_fast;
                split_prev = fast;
                fast = next_fast;
            }
        }
        
        return (&dummyHead)->next;
    }
};
// @lc code=end

