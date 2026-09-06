class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;

        if (!root)
            return ans;

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* node = st.top();
            st.pop();

            ans.push_back(node->val);

            for (int i = node->children.size() - 1; i >= 0; --i)
                st.push(node->children[i]);
        }

        return ans;
    }
};