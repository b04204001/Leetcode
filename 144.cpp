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
    void Preorder(TreeNode* cur, vector<int> &ans){
        if(cur) {
            ans.push_back(cur->val);
            Preorder(cur->left,ans);
            Preorder(cur->right,ans);   
        }
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        Preorder(root,ans);
        return ans;
    }
};

