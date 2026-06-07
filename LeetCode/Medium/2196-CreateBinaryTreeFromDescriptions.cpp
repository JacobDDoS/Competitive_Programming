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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> st;
        for (vector<int>& node : descriptions) {
            TreeNode* parent, *child;
            st.insert(node[1]);
            if (!mp[node[0]]) {
                parent = new TreeNode(node[0], nullptr, nullptr);
                mp[node[0]] = parent;
            } else {
                parent = mp[node[0]];
            }
            if (!mp[node[1]]) {
                child = new TreeNode(node[1], nullptr, nullptr);
                mp[node[1]] = child;
            } else {
                child = mp[node[1]];
            }
            if (node[2]) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }
        for (auto& pr : mp) {
            if (!st.count(pr.first)) {
                return mp[pr.first];
            }
        }
        return nullptr;
    }
};