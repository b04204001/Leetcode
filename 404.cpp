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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0 ;

        int sum = 0;
        
        if (root->left) {
            // 判斷左節點是否為「葉子」
            if (!root->left->left && !root->left->right) {
                sum += root->left->val;
            } else {
                // 如果左節點不是葉子，就繼續往左邊找
                sum += sumOfLeftLeaves(root->left);
            }
        }
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};
