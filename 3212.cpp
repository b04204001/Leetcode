class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        
        // 【垂直歷史紀錄器 (1D Array)】
        // sumX[j] 記錄：從第 0 列往下走到目前的第 i 列，整個「第 j 行 (Column)」累積了幾個 X
        // 透過一維陣列保存歷史狀態，成功將空間複雜度從 O(M*N) 壓縮到 O(N)
        vector<int> sumX(col, 0);
        vector<int> sumY(col, 0);
        
        for(int i = 0; i < row; i++){
            // 【水平掃描器】
            // 每換到一個新的 Row，掃描器歸零。
            // 負責記錄「當下這個 Row」從最左邊 (0) 到目前位置 (j) 有幾個 X 和 Y
            int nX = 0;
            int nY = 0;
            
            for(int j = 0; j < col; j++){
                // 1. 更新水平掃描器：看當下踩到的這格是什麼
                if(grid[i][j] == 'X') nX++;
                else if(grid[i][j] == 'Y') nY++;
                
                // 2. 疊積木魔法 (2D Prefix Sum 核心狀態轉移)
                // 將「當下這一條橫截面的數量 (nX)」加入「上方的歷史總和 (sumX[j])」
                // 物理意義：大矩形總和 = 上方舊矩形總和 + 底部最新一條橫截面
                sumX[j] += nX;
                sumY[j] += nY;
                
                // 3. 結算判定
                // 因為題目規定子矩形必須包含左上角 grid[0][0]
                // 此時的 sumX[j] 就是完美涵蓋 (0,0) 到 (i,j) 範圍的 X 總數
                // 條件 A: 至少包含一個 X (sumX[j] > 0)
                // 條件 B: X 和 Y 的數量相等 (sumX[j] == sumY[j])
                if(sumX[j] > 0 && sumX[j] == sumY[j]){
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
