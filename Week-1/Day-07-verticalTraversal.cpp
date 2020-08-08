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
    void util(TreeNode* root, map<pair<int, int>, vector<int> >& m, int x, int y){
        if(root==NULL)
            return;
        m[{x, y}].push_back(root->val);
        util(root->left, m, x-1, y+1);
        util(root->right, m, x+1, y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int, int>, vector<int> > m;
        util(root, m, 0, 0);
        vector<vector<int> > ans;
        for(auto it=m.begin(); it!=m.end(); it++)
            sort(it->second.begin(), it->second.end());
        int prev;
        for(auto it=m.begin(); it!=m.end(); it++){
            if(it!=m.begin() && it->first.first==prev){
                for(auto n: it->second)
                    ans.back().push_back(n);
            }
            else
                ans.push_back(it->second);
            prev=it->first.first;
        }
        return ans;
    }
};
