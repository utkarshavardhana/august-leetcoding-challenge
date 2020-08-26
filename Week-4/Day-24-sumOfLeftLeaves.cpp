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
    void traverse(TreeNode* root, int &res) {
        if(!root)   return;
        if(root->left and !root->left->left and !root->left->right) res += root->left->val;
        traverse(root->left, res);
        traverse(root->right, res);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)   return 0;
        int res = 0;
        traverse(root, res);
        return res;
    }
};
