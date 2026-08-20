class WordDictionary {
public:
    struct Node {
        Node* children[26];
        bool isEnd;

        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* curr = root;

        for (char c : word) {
            int index = c - 'a';

            if (curr->children[index] == nullptr)
                curr->children[index] = new Node();

            curr = curr->children[index];
        }

        curr->isEnd = true;
    }

    bool dfs(Node* node, string& word, int index) {
        if (index == word.size())
            return node->isEnd;

        char c = word[index];

        if (c != '.') {
            int idx = c - 'a';

            if (node->children[idx] == nullptr)
                return false;

            return dfs(node->children[idx], word, index + 1);
        }

        // '.' can represent any character
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                if (dfs(node->children[i], word, index + 1))
                    return true;
            }
        }

        return false;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};