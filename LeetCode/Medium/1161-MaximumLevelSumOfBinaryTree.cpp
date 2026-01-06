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
    int maxLevelSum(TreeNode* root) {
        int best = 1, curLevel = 1, maxSum = root->val, temp = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            queue<TreeNode*> nq;
            temp = 0;
            while (!q.empty()) {
                auto ptr = q.front(); q.pop();
                temp += ptr->val;
                if (ptr->left) nq.push(ptr->left);
                if (ptr->right) nq.push(ptr->right);
            }

            if (temp > maxSum) {
                maxSum = temp; 
                best = curLevel;
            }
            curLevel++;
            q = nq;
        }

        return best;
    }
};