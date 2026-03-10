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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr){
            return true;
        }
        if(p == nullptr || q == nullptr){
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        bool leftbool = isSameTree(p->left,q->left);
        bool rightbool = isSameTree(p->right,q->right);
        return leftbool && rightbool;
        // 【韌體老手的一行流寫法，你可以把上面三行濃縮成這行】：
        // return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
