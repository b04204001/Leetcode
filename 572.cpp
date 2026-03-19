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
    bool isSamtree(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr && root2 == nullptr) return true;
        if(root1 == nullptr || root2 == nullptr) return false;
        if(root1->val != root2->val) return false;
        return isSamtree(root1->left, root2->left) && isSamtree(root1->right,root2->right) ;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // 💡 煞車 1：如果你要找的小樹是空的，那到處都是 (雖然題目說 subRoot 不會是空，但防禦性編程很加分)
        if(subRoot == nullptr) return true;
        
        // 💡 煞車 2 (你漏掉的防彈衣！)：如果大樹已經被找光了(空了)，直接宣告失敗，不要再往下找 left/right 了！
        if(root == nullptr) return false;
        if(isSamtree(root,subRoot)) return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot) ;
    }
};
