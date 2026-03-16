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
    //雙指標形式，
    bool isSymmetric(TreeNode* root) {
        if(!root) return false;
        return check(root->left,root->right);
    }

    bool check(TreeNode* l , TreeNode* r){
        if(l == nullptr && r==nullptr) return true;
        if(l == nullptr || r==nullptr) return false;
        if(l->val != r->val) return false;
        return ( check(l->left,r->right) && check(l->right,r->left) ) ;
    }
};
