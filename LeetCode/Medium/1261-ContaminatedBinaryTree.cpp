#include <bits/stdc++.h>
using namespace std;

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
class FindElements {
    public:
        unordered_set<int> elements;
        FindElements(TreeNode* root) {
            root->val = 0;
            elements.insert(0);
            queue<TreeNode*> q;
            q.push(root);
            int qSize = 1;
            while (q.size()) {
                TreeNode* curNode = q.front(); q.pop();
                if (curNode->left) {
                    elements.insert(curNode->val*2+1);
                    q.push(curNode->left);
                    curNode->left->val = curNode->val*2+1;
                }
    
                if (curNode->right) {
                    elements.insert(curNode->val*2+2);
                    q.push(curNode->right);
                    curNode->right->val = curNode->val*2+2;
                }
                
                qSize--;
                if (qSize == 0) {
                    qSize = q.size();
                }
            }
        }
        
        bool find(int target) {
            return elements.count(target);
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */