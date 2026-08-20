class Trie {
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

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* curr = root;

        for (char c : word) {
            int index = c - 'a';

            if (curr->children[index] == nullptr)
                curr->children[index] = new Node();

            curr = curr->children[index];
        }

        curr->isEnd = true;
    }

    bool search(string word) {
        Node* curr = root;

        for (char c : word) {
            int index = c - 'a';

            if (curr->children[index] == nullptr)
                return false;

            curr = curr->children[index];
        }

        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        Node* curr = root;

        for (char c : prefix) {
            int index = c - 'a';

            if (curr->children[index] == nullptr)
                return false;

            curr = curr->children[index];
        }

        return true;
    }
};