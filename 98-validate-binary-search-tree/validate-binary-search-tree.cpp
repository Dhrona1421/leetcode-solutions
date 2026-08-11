class Solution {
public:
    bool valid(TreeNode* root, long long low, long long high) {
        if (!root) return true;

        if (root->val <= low || root->val >= high)
            return false;

        return valid(root->left, low, root->val) &&
               valid(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
};