/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* dummyHead = new ListNode(-1000);
        dummyHead->next = head;
        ListNode* l = dummyHead;
        ListNode* r = head;
        while (r != nullptr) {
            while (l->val == r->val) {
                l->next = r->next;
                r = l->next;
                if (r == nullptr) break;
            }
            if (r != nullptr) {
                r = r->next;
                l = l->next;
            }
        }
        return dummyHead->next;
    }
};
// @lc code=end

