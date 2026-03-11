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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int countl = 0;
        int countr = 0;
        if (root->left != nullptr ) {
            countl = countNodes(root->left);
        }
        
        if (root->right != nullptr ) {
            countr = countNodes(root->right);
        }
        
        int count = countl + countr + 1;
        return count;
    }
};
