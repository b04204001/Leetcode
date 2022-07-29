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
    void Inorder(TreeNode* cur, vector<int> &ans){
        if(cur){
            Inorder(cur->left,ans);
            ans.push_back(cur->val);
            Inorder(cur->right,ans);
        }
    } 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur= root;
        Inorder(cur,ans);
        return ans;
    }
};
