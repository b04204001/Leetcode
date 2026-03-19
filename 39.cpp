class Solution {
public:
    // 建立一個全域的「大寶箱」，用來裝所有成功的組合
    vector<vector<int>> ans; 
    
    // ⚙️ 核心遞迴函式：DFS 賞金獵人
    // candidates: 所有的硬幣種類
    // target: 目標金額
    // current_sum: 目前籃子裡的總金額
    // start_index: 從哪個硬幣開始挑 (為了避免重複組合，例如拿了 3 就不能回頭拿 2)
    // basket: 目前手上的這個籃子裡裝了哪些硬幣
    void dfs(vector<int>& candidates, int target, int current_sum, int start_index, vector<int>& basket) {
        
        // 💡 煞車條件 1：爆炸了 (Bust)
        if (current_sum > target) {
            return; // 總金額超過了，這條路行不通，直接退回上一步！
        }
        
        // 💡 煞車條件 2：中大獎了！(Bingo)
        if (current_sum == target) {
            ans.push_back(basket); // 把手上的籃子複製一份，丟進大寶箱裡存起來
            return;                // 任務達成，退回上一步找其他可能！
        }
        
        // 💡 核心迴圈：站在目前的硬幣上，繼續往下挖
        // 為什麼從 start_index 開始？因為如果我們現在決定拿 3，以後就只能拿 3 或比 3 後面的硬幣，不能回頭拿 2，這樣才不會出現 [2,3] 和 [3,2] 這種重複的答案。
        for (int i = start_index; i < candidates.size(); i++) {
            
            // 👉 動作 1：塞進去 (Push)
            basket.push_back(candidates[i]); // 把硬幣丟進籃子
            current_sum += candidates[i];    // 記帳：總金額增加
            
            // 👉 動作 2：往下深挖 (Dive)
            // 注意！這裡傳入的是 'i' 而不是 'i+1'。
            // 意思是：「因為硬幣無限量供應，所以我下一步『還可以繼續選同一顆硬幣』！」
            dfs(candidates, target, current_sum, i, basket);
            
            // 👉 動作 3：拔出來 (Backtrack / Pop)
            // 當上面的 dfs 結束退回來時 (不管是爆炸了、中獎了、還是到底了)，
            // 我們必須把剛剛丟進去的硬幣「拿出來」，把金額「扣回去」，
            // 這樣這個籃子才能乾乾淨淨地去裝下一個種類的硬幣！
            basket.pop_back(); 
            current_sum -= candidates[i]; 
        }
    }

    // 👑 主程式：發號施令
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> basket; // 給賞金獵人一個空籃子
        
        // 呼叫 DFS 開始找：目前金額 0，從第 0 個硬幣開始挑
        dfs(candidates, target, 0, 0, basket); 
        
        return ans; // 最後把裝滿成功組合的大寶箱交出去
    }
};
