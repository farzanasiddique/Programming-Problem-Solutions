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
    void postordTrv (TreeNode* node) {
        if (node == NULL) {
            return;
        } else {
            postordTrv(node->left);
            postordTrv(node->right);
            treeVals.push_back(node->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postordTrv(root);
        return treeVals;
    }
};
