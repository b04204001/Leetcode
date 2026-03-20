class Solution {
public:
    vector<vector<int>> ans;
    
    // ⚙️ 核心遞迴：子集探險家
    void dfs(vector<int>& nums, vector<int>& curr, int start) {
        
        // 🌟 Subsets 專屬動作：不管三七二十一，先進來的籃子就是一個合法子集！
        // (第一次傳進來是空籃子 []，也會在這裡被完美收錄)
        ans.push_back(curr); 
        
        // 💡 核心迴圈：站在目前的起點 (start)，看向後面還有哪些硬幣可以拿
        // 這個 for 迴圈必須放在 dfs 裡面，才能做到「平行宇宙」的探索！
        for(int i = start; i < nums.size(); i++){
            
            // 👉 動作 1：塞進去
            curr.push_back(nums[i]);
            
            // 👉 動作 2：往下深挖
            // 注意！因為每個數字只能拿一次，所以下一步必須從 i + 1 開始！
            dfs(nums, curr, i + 1);
            
            // 👉 動作 3：拔出來 (Backtrack / Pop)
            // 退回來了！把剛剛拿的硬幣拿出來，才能去試迴圈裡的下一個硬幣 (例如退掉 2，準備去拿 3)
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr; // 給探險家一個空籃子
        
        // 呼叫 DFS 開始找：從第 0 顆硬幣開始挑
        dfs(nums, curr, 0);
        
        return ans;
    }
};
