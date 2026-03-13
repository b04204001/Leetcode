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

    int getHight(TreeNode* root ){
        if (root == NULL) {
            return 0; // 若定義空樹高度為-1，則此處返回 -1
        }
        int left = getHight(root->left);
        int right = getHight(root->right);
        if ( left > right){
            return left + 1;
        }
        else{
            return right + 1;
        }
    }

    int maxDepth(TreeNode* root) {
        int h = getHight(root);
        return h;
    }
};




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
    int maxDepth(TreeNode* root ){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr ) return 1;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return max(lh,rh) + 1;
    }
};
