class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(TreeNode* root, int targetSum) {
        if (!root)
            return;

        path.push_back(root->val);
        targetSum -= root->val;

        if (!root->left && !root->right && targetSum == 0)
            ans.push_back(path);

        dfs(root->left, targetSum);
        dfs(root->right, targetSum);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};