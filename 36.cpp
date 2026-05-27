class Solution {
public:
    bool isvalid(vector<vector<char>>& board,int i , int j){
        int m = board.size();
        int n = board[0].size();
        //col
        for(int k =0 ; k<n ;k++){
            if(k == j) continue;
            if(board[i][k] == board[i][j]) return false;
        }
        //row
        for(int k =0 ; k<m ;k++){
            if(k == i) continue;
            if(board[k][j] == board[i][j]) return false;
        }
        //square
        int r = i / 3;
        int c = j / 3;
        for(int k = 0; k<3;k++){
            for(int l = 0; l <3;l++){
                if(3 *r +k == i && 3 *c + l == j) continue;
                if(board[3*r+k][3*c+l] == board[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0;i <m;i++){
            for(int j = 0; j <n;j++){
                if(board[i][j] != '.'){
                    if( !isvalid(board,i,j)){
                        return false;
                    }
                }

            }
        }
        return true;
    }
};

//最優解:
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 使用 bool 陣列記錄數字 1-9 在各行列宮是否出現過
        // 陣列大小為 9x9，初始化皆為 false
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // 1. 遇到空白格直接跳過
                if (board[i][j] == '.') continue;
                
                // 2. 將字元 '1'-'9' 對應到索引 0-8
                int num = board[i][j] - '1'; 
                
                // 3. 計算目前座標屬於哪一個九宮格 (編號 0-8)
                int box_index = (i / 3) * 3 + (j / 3); 
                
                // 4. 核心檢查：如果該數字在「同列」、「同欄」或「同宮」已經出現過，立刻判定非法
                if (rows[i][num] || cols[j][num] || boxes[box_index][num]) {
                    return false;
                }
                
                // 5. 第一次遇到，將狀態標記為 true
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[box_index][num] = true;
            }
        }
        return true;
    }
};

