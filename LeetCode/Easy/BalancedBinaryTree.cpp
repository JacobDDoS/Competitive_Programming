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
    int nodeHeight(TreeNode* node) {
        if (!node) {
            return 0;
        }
        if (!node->left && !node->right) {
            return 1;
        }
        
        int left = 0;
        int right = 0;
        if (node->left) {
            left = nodeHeight(node->left);
        }
        if (node->right) {
            right = nodeHeight(node->right);
        }
        
        if (abs(left-right) > 1 || left==-1 || right==-1) {
            return -1;
        } else {
            return max(left+1, right+1);
        }
    }
    bool isBalanced(TreeNode* root) {
        return nodeHeight(root) != -1;
    }
};