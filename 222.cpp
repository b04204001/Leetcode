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



method 2

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        
        // 1. 派出兩個探路員，一個瘋狂往左衝，一個瘋狂往右衝
        int left_h = 0, right_h = 0;
        TreeNode* l_curr = root;
        TreeNode* r_curr = root;
        
        while (l_curr != nullptr) {
            left_h++;
            l_curr = l_curr->left;
        }
        while (r_curr != nullptr) {
            right_h++;
            r_curr = r_curr->right;
        }
        
        // 2. 如果左右深度一樣，代表這是一棵「滿二元樹」！
        // 直接用你的位元魔法秒殺，不用再往下遞迴了！
        if (left_h == right_h) {
            return (1 << left_h) - 1;
        }
        
        // 3. 如果深度不一樣，代表底層有缺口
        // 乖乖切兩半，交給下一層繼續判斷
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
