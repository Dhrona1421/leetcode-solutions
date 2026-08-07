class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head), *fast = &dummy, *slow = &dummy;
        while (n--) fast = fast->next;
        while (fast->next) fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return dummy.next;
    }
};