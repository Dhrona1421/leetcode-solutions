class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);
        string word, ans;

        while (ss >> word) {
            string root = word;

            for (int i = 1; i <= word.size(); i++) {
                string prefix = word.substr(0, i);

                if (st.count(prefix)) {
                    root = prefix;
                    break;
                }
            }

            if (!ans.empty())
                ans += " ";

            ans += root;
        }

        return ans;
    }
};