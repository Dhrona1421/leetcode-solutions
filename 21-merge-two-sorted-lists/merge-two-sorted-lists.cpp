class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode dummy(0), *cur = &dummy;
        while (a && b) {
            if (a->val <= b->val) cur->next = a, a = a->next;
            else cur->next = b, b = b->next;
            cur = cur->next;
        }
        cur->next = a ? a : b;
        return dummy.next;
    }
};