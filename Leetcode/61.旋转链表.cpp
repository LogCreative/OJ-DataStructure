/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* slow = head;
        ListNode* last = head;
        while(slow) {
            last = slow;
            slow = slow->next;
            ++n;
        }
        if (n == 0) return head;
        k = k % n;
        if (k == 0) return head;
        int rev = n - k;
        slow = head;
        ListNode* new_tail;
        while (rev--) {
            new_tail = slow;
            slow = slow->next;
        }
        new_tail->next = nullptr;
        last->next = head;
        return slow;
    }
};
// @lc code=end

