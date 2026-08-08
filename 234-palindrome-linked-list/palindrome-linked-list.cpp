class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        
        int l = 0, r = v.size() - 1;
        while (l < r) {
            if (v[l++] != v[r--])
                return false;
        }
        
        return true;
    }
};