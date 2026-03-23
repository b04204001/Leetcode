//優解
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
    bool helper(TreeNode* root,long low ,long high){
        //邊界
        if(root == nullptr) return true;
        //這層 用 否定
        if(  root->val >= high || root->val <= low) return false;
        //遞迴
        return helper(root->left,low,root->val) && helper(root->right,root->val,high);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
};
//帶上下界去遞迴，BST需要左數都小於節點，不能只比root跟左右 ，用long因為測資有int_min max無法使用。
