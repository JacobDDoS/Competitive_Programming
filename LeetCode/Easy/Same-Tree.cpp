class Solution {
public:
    vector<int> val1; vector<int> val2;
    void dfs(TreeNode* n, vector<int>& val) {
        if (!n) {
            val.push_back(-999999);
            return;
        }
        val.push_back(n->val);
        dfs(n->left, val);
        dfs(n->right, val);
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        dfs(p, val1); dfs(q, val2);
        if (val1.size() != val2.size()) {
            return false;
        }
        for (int i=0;i<val1.size();i++) {
            if (val1[i] != val2[i]) {
                return false;
            }
        }
        return true;
    }
};