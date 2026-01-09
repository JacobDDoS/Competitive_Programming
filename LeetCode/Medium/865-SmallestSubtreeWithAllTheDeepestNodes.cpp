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
    vector<int> cnt;
    int depth;

    int depthBFS(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int dep = -1;
        while (!q.empty()) {
            dep++;
            queue<TreeNode*> nq;
            while (!q.empty()) {
                TreeNode* cur = q.front(); q.pop();
                if (cur->left) nq.push(cur->left);
                if (cur->right) nq.push(cur->right);
            }
            q = nq;
        }
        return dep;
    }

    void dfs(TreeNode* root, int cur) {
        if (cur == depth) {
            cnt[root->val] = 1;
            return;
        }

        if (root->left) dfs(root->left, cur+1);
        if (root->right) dfs(root->right, cur+1);

        cnt[root->val] = (root->left ? cnt[root->left->val] : 0) + (root->right ? cnt[root->right->val] : 0);
    }

    TreeNode* bfsToSubtree(TreeNode* root) {
        int target = cnt[root->val];
        TreeNode* ans;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            queue<TreeNode*> nq;
            while (!q.empty()) {
                TreeNode* cur = q.front(); q.pop();
                if (cur->left) nq.push(cur->left);
                if (cur->right) nq.push(cur->right);

                if (cnt[cur->val] == target) ans = cur;
            }
            q = nq;
        }
        return ans;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        cnt = vector<int>(500, 0);
        depth = depthBFS(root);
        dfs(root, 0);
        return bfsToSubtree(root);
    }
};