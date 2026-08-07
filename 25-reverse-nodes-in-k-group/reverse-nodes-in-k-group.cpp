class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head), *prev = &dummy;

        while (true) {
            ListNode* end = prev;
            for (int i = 0; i < k && end; ++i)
                end = end->next;

            if (!end) break;

            ListNode* cur = prev->next;
            ListNode* next = cur->next;

            for (int i = 1; i < k; ++i) {
                cur->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = cur->next;
            }

            prev = cur;
        }

        return dummy.next;
    }
};