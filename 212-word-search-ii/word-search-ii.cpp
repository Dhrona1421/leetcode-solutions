class Solution {
public:
    struct Node {
        Node* children[26];
        int wordIndex;

        Node() {
            wordIndex = -1;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    Node* root = new Node();
    vector<string> ans;

    void insert(string& word, int index) {
        Node* curr = root;

        for (char c : word) {
            int i = c - 'a';

            if (!curr->children[i])
                curr->children[i] = new Node();

            curr = curr->children[i];
        }

        curr->wordIndex = index;
    }

    void dfs(vector<vector<char>>& board, int r, int c, Node* node,
             vector<string>& words) {

        if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size() ||
            board[r][c] == '#')
            return;

        int index = board[r][c] - 'a';

        if (!node->children[index])
            return;

        Node* next = node->children[index];

        // Found a complete word
        if (next->wordIndex != -1) {
            ans.push_back(words[next->wordIndex]);

            // Prevent duplicate results
            next->wordIndex = -1;
        }

        char original = board[r][c];
        board[r][c] = '#';

        dfs(board, r + 1, c, next, words);
        dfs(board, r - 1, c, next, words);
        dfs(board, r, c + 1, next, words);
        dfs(board, r, c - 1, next, words);

        board[r][c] = original;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        for (int i = 0; i < words.size(); i++)
            insert(words[i], i);

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                dfs(board, r, c, root, words);
            }
        }

        return ans;
    }
};