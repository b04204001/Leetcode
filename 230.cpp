//20200418 inorder

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
    int ans;
    int kthSmallest(TreeNode* root, int &k) {
        if(root){
            kthSmallest(root->left,k);
            if(--k == 0){
                ans=root->val;
                return ans;
            }
            kthSmallest(root->right,k);
        }
        return ans;
    }
};
//用Inorder


