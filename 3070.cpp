class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        
        // 📚 只需要一本垂直歷史紀錄本
        // colSum[j] 記錄：從 (0, 0) 到 (i-1, j) 的舊矩形總和
        vector<int> colSum(col, 0); 
        
        for(int i = 0; i < row; i++){
            
            // 🔦 只需要一個水平掃描器
            // 負責記錄當下這個 Row，從左邊 0 累積到 j 的總和
            int rowSum = 0; 
            
            for(int j = 0; j < col; j++){ // 💡 修正視力測驗 Bug：這裡是 col
                
                // 1. 水平掃描器往前推進，把現在踩到的數字吃進去
                rowSum += grid[i][j];
                
                // 2. 疊積木魔法！
                // 新的超大矩形總和 = 上方的歷史舊矩形 (colSum[j]) + 底部剛掃描完的橫截面 (rowSum)
                colSum[j] += rowSum;
                
                // 3. 結算：如果這個超大矩形的總和 <= k，就得分！
                if(colSum[j] <= k){
                    ans += 1;
                } else {
                    // 💡 小優化 (Optional)：
                    // 因為題目說陣列裡面都是「非負整數」，
                    // 如果現在總和已經 > k 了，那繼續往右走只會越來越大，絕對不可能再 <= k。
                    // 但因為下方可能還有其他判斷需求，通常這題不提早 break 也不會 Timeout。
                }
            }
        }
        return ans;
    }
};
