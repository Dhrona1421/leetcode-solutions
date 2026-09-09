class Solution {
public:
    int dfs(TreeNode* root, long long target, unordered_map<long long, int>& mp, long long sum) {
        if (!root)
            return 0;

        sum += root->val;

        int ans = mp.count(sum - target) ? mp[sum - target] : 0;

        mp[sum]++;

        ans += dfs(root->left, target, mp, sum);
        ans += dfs(root->right, target, mp, sum);

        mp[sum]--;

        return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp;
        mp[0] = 1;

        return dfs(root, targetSum, mp, 0);
    }
};