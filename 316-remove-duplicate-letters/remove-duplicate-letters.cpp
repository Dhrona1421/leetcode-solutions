class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, 0);
        vector<bool> used(26, false);
        string st;

        for (int i = 0; i < s.size(); ++i)
            last[s[i] - 'a'] = i;

        for (int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a';

            if (used[c])
                continue;

            while (!st.empty() &&
                   st.back() > s[i] &&
                   last[st.back() - 'a'] > i) {
                used[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(s[i]);
            used[c] = true;
        }

        return st;
    }
};