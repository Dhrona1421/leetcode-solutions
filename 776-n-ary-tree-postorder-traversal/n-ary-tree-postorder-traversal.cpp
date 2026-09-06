class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;

        if (!root)
            return ans;

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* node = st.top();
            st.pop();

            ans.push_back(node->val);

            for (Node* child : node->children)
                st.push(child);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};