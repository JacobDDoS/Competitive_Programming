class Solution {
public:
    vector<int> nums;
    void traverse(TreeNode* root) {
        if (!root) return;
        if (root->left) {
            inorderTraversal(root->left);
        }
        nums.push_back(root->val);
        if (root->right) {
            inorderTraversal(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return nums;
    }
};