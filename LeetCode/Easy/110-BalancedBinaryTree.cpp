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
    unordered_map<TreeNode*,int> height;
    int calculateHeight(TreeNode* node) {
        int h = 1;
        if (node->left) h = calculateHeight(node->left) + 1;
        if (node->right) h = max(h, calculateHeight(node->right) + 1);

        height[node] = h;
        return h;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (height[root] == 0) calculateHeight(root);

        int leftH = 0, rightH = 0;
        if (root->left) leftH = height[root->left];
        if (root->right) rightH = height[root->right];

        if (abs(rightH-leftH) > 1) return false;
        if (root->left && !isBalanced(root->left)) return false;
        if (root->right && !isBalanced(root->right)) return false;

        return true;
    }
};