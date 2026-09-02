class MagicDictionary {
public:
    unordered_map<int, vector<string>> mp;

    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {
        for (auto& word : dictionary)
            mp[word.size()].push_back(word);
    }

    bool search(string searchWord) {
        int n = searchWord.size();

        for (auto& word : mp[n]) {
            int diff = 0;

            for (int i = 0; i < n; i++) {
                if (word[i] != searchWord[i]) {
                    diff++;
                    if (diff > 1) break;
                }
            }

            if (diff == 1)
                return true;
        }

        return false;
    }
};