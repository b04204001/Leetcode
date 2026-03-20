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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int levelcnt = 0;
        while(!q.empty()){
            int levelsize = q.size();
            vector<int> level;
            for(int i = 0 ; i < levelsize;i++){
                TreeNode* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            if(levelcnt % 2 != 0){
                reverse(level.begin(),level.end());
            }
            ans.push_back(level);
            levelcnt++;
        }
        return ans;
    }
};
