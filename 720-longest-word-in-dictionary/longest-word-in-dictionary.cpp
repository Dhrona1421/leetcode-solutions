class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());

        unordered_set<string> st;
        string ans = "";

        for (string& word : words) {
            if (word.size() == 1 || st.count(word.substr(0, word.size() - 1))) {
                st.insert(word);

                if (word.size() > ans.size())
                    ans = word;
            }
        }

        return ans;
    }
};