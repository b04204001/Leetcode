class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        // 如果有p / q慢慢回傳數值回來，每上一層，就找到一個p/q祖先
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // 往左右找p q
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // 左右都有 → 關鍵分岔點
        if (left && right) return root;

        // 否則回傳有找到的那邊
        return left ? left : right;
    }
};
