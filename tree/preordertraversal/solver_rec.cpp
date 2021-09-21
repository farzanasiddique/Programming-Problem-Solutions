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
    vector <int> treeVals;
    void preordTrv (TreeNode* node) {
        if (node == NULL) {
            return;
        } else {
            treeVals.push_back(node->val);
            preordTrv(node->left);
            preordTrv(node->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preordTrv(root);
        return treeVals;
    }
};
