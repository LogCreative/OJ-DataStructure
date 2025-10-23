/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans_dummy = new ListNode();
        ListNode* cur = ans_dummy;
        int carry = 0;
        ListNode* cur1 = l1, *cur2 = l2;
        while (cur1 != nullptr || cur2 != nullptr || carry > 0) {
            int sum = carry;
            if (cur1 != nullptr) {
                sum += cur1->val;
                cur1 = cur1->next;
            }
            if (cur2 != nullptr) {
                sum += cur2->val;
                cur2 = cur2->next;
            }
            ListNode* new_digit = new ListNode(sum % 10);
            cur->next = new_digit;
            cur = cur->next;
            carry = sum / 10;
        }
        return ans_dummy->next;
    }
};
// @lc code=end

