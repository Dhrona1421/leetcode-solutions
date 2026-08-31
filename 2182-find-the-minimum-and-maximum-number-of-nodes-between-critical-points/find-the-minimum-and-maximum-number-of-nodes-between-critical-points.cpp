class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, prevCritical = -1;
        int minDist = INT_MAX;
        int pos = 1;

        int prevVal = head->val;
        head = head->next;

        while (head->next) {
            int currVal = head->val;
            int nextVal = head->next->val;

            bool critical = (currVal > prevVal && currVal > nextVal) ||
                            (currVal < prevVal && currVal < nextVal);

            if (critical) {
                if (first == -1) {
                    first = pos;
                } else {
                    minDist = min(minDist, pos - prevCritical);
                }

                prevCritical = pos;
            }

            prevVal = currVal;
            head = head->next;
            pos++;
        }

        if (first == prevCritical)
            return {-1, -1};

        return {minDist, prevCritical - first};
    }
};