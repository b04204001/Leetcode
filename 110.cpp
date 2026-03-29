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
    int dfs_height(TreeNode* root ){
        if(root == nullptr) return 0;
        return 1 + max(dfs_height(root->left), dfs_height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        int lh = dfs_height(root->left);
        int rh = dfs_height(root->right);
        if(abs(rh - lh) > 1) return false;
        
        return isBalanced(root->left) && isBalanced(root->right);;
    }
};

//優解
class Solution {
public:
    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        if (left == -1) return -1;

        int right = dfs(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};
