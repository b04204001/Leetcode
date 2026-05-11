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
    void Inorder(TreeNode* cur, vector<int> &ans){
        if(cur){
            Inorder(cur->left,ans);
            ans.push_back(cur->val);
            Inorder(cur->right,ans);
        }
    } 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur= root;
        Inorder(cur,ans);
        return ans;
    }
};


// stack法
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
    void dfs(TreeNode* t,vector<int>& ans){
        if(t == NULL) return;
        dfs(t->left,ans);
        ans.push_back(t->val);
        dfs(t->right,ans);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        //遞回法
        //dfs(root, ans);

        //stack法
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(!st.empty() || curr != nullptr){
            // 1. 一路向左：把左側所有節點都壓入棧
            while(curr != nullptr){
                st.push(curr);
                curr = curr->left;
            }
            // 2. 觸底反彈：取出最後一個左節點（或是目前的根節點）
            curr = st.top();
            st.pop();

            // 3. 處理數值
            ans.push_back(curr->val);

            // 4. 轉向右子樹：重複上述邏輯
            curr = curr->right;
        }
        return ans;
    }
};
