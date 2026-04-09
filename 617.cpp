class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // 如果其中一邊為空，直接回傳另一邊（包含兩者皆空的情況）
        if (!root1) return root2;
        if (!root2) return root1;

        // 兩者皆不為空，合併數值
        root1->val += root2->val;

        // 遞迴合併左子樹與右子樹，並更新 root1 的指標
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};
