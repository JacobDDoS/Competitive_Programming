/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int MOD = 1e9 + 7;
    unordered_map<TreeNode*, long long> mp;
    long long allSum;
    long long findSum(TreeNode* ptr) {
        long long ans = ptr->val;
        if (ptr->left) ans += findSum(ptr->left);
        if (ptr->right) ans += findSum(ptr->right);

        mp[ptr] = ans;
        return ans;
    }
    long long findBest(TreeNode* ptr) {
        long long cur = -99999999;
        if (ptr->left) {
            cur = max(cur, mp[ptr->left] * (allSum - mp[ptr->left])); 
            cur = max(cur, findBest(ptr->left));
        }
        if (ptr->right) {
            cur = max(cur, mp[ptr->right] * (allSum - mp[ptr->right]));
            cur = max(cur, findBest(ptr->right));
        }

        return cur;
    }
    int maxProduct(TreeNode* root) {
        allSum = findSum(root);
        return findBest(root) % MOD;
    }
};