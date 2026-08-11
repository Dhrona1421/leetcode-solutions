class Solution {
public:
    int ans = INT_MIN;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        ans = max(ans, root->val + left + right);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};