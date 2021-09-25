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
    vector <int> sortedLst;
    stack <TreeNode*> nodeSt;
    void trvInord(TreeNode* node) {
        nodeSt.push(node);
        node = node->left;
        while (!nodeSt.empty()) {
            while(true) {
                if (node == NULL) break;
                nodeSt.push(node);
                node = node->left;
            }
            node = nodeSt.top();
            nodeSt.pop();
            sortedLst.push_back(node->val);
            node = node->right;
            if (node!=NULL) {
                nodeSt.push(node);
                node = node->left;
            }
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(root != NULL) trvInord(root);
        return sortedLst;
    }
};
