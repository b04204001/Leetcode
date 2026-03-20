class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 最終答案：每一層一個 vector
        vector<vector<int>> ans;

        // Edge case：空樹直接回傳空
        if (root == nullptr) return ans;

        // BFS 核心資料結構：queue（先進先出）
        queue<TreeNode*> q;

        // 先把 root 放進 queue，作為第一層起點
        q.push(root);

        // 當 queue 還有節點，就持續做 BFS
        while (!q.empty()) {

            // ⭐ 關鍵：目前 queue 裡的數量 = 這一層的節點數
            int levelSize = q.size();

            // 用來存「這一層的所有節點值」
            vector<int> level;

            // 處理「這一層的所有節點」
            for (int i = 0; i < levelSize; i++) {

                // 取出 queue 最前面的節點
                TreeNode* node = q.front();
                q.pop();  // 記得移除

                // 把這個節點的值放進當前層
                level.push_back(node->val);

                // 如果有左子節點，加入 queue（下一層會用到）
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                // 如果有右子節點，也加入 queue
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            // ⭐ 一整層處理完後，放進答案
            ans.push_back(level);
        }

        return ans;
    }
};
