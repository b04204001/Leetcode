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
    void Postorder(TreeNode* cur, vector<int> &ans){
        if(cur){
            Postorder(cur->left,ans);
            Postorder(cur->right,ans);
            ans.push_back(cur->val);
        }
    } 
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur= root;
        Postorder(cur,ans);
        return ans;
    }
};
