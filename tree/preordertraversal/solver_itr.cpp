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
    vector<int> preorderTraversal(TreeNode* root) {
        stack <TreeNode*> nodeSt;
        TreeNode* currNode;
        nodeSt.push(root);
        while(!nodeSt.empty()) {
            currNode = nodeSt.top();
            nodeSt.pop();
            if (currNode != NULL) {
                nodeSt.push(currNode->right);
                nodeSt.push(currNode->left);
                treeVals.push_back(currNode->val);
            }
        }
        return treeVals;
    }
};
