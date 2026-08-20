class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;

    vector<string> dfs(int start, string& s) {
        if (start == s.size())
            return {""};

        if (memo.count(start))
            return memo[start];

        vector<string> result;
        string word;

        for (int end = start; end < s.size(); end++) {
            word += s[end];

            if (dict.find(word) == dict.end())
                continue;

            vector<string> suffixes = dfs(end + 1, s);

            for (string& suffix : suffixes) {
                if (suffix.empty())
                    result.push_back(word);
                else
                    result.push_back(word + " " + suffix);
            }
        }

        return memo[start] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict.insert(wordDict.begin(), wordDict.end());
        return dfs(0, s);
    }
};