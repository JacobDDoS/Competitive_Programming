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
    bool hasNodeLeft(vector<TreeNode*>& layer) {
        for (TreeNode* ptr : layer) {
            if (ptr != nullptr) {
                return true;
            } 
        }
        return false;
    }
    bool isLayerSymmetric(vector<TreeNode*>& layer) {
        int l=0, r=layer.size()-1;
        while (l<r) {
            if (layer[l]==nullptr && layer[r] == nullptr){
                l++;
                r--;
            }
            else if (layer[l]!=nullptr && layer[r]!=nullptr && (layer[l]->val == layer[r]->val)) {
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> currentLayer;
        currentLayer.push_back(root);
        while (hasNodeLeft(currentLayer)) {
            if (!isLayerSymmetric(currentLayer)) return false;
            vector<TreeNode*> newLayer;
            for (TreeNode* node : currentLayer) {
                if (node == nullptr) {
                    newLayer.push_back(nullptr);
                    newLayer.push_back(nullptr);
                } else {
                    newLayer.push_back(node->left);
                    newLayer.push_back(node->right);
                }
            }
            currentLayer = newLayer;
        }
        return true;
    }
};