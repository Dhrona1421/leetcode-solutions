class Solution {
public:
    int ans = 0;

    struct Info {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };

    Info dfs(TreeNode* root) {
        if (!root)
            return {true, INT_MAX, INT_MIN, 0};

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        if (left.isBST && right.isBST &&
            root->val > left.maxVal &&
            root->val < right.minVal) {

            int sum = left.sum + right.sum + root->val;
            ans = max(ans, sum);

            return {
                true,
                min(left.minVal, root->val),
                max(right.maxVal, root->val),
                sum
            };
        }

        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};