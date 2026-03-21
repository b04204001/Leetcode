class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        // 🌟 設定上下兩個指標
        int top = x;
        int bottom = x + k - 1;
        
        // 當上指標還在下指標的上方時，就一直互相對調
        while (top < bottom) {
            
            // 🚗 針對子矩陣範圍內的每一個直行 (Column)
            for (int j = y; j < y + k; j++) {
                // 上下數字交換！
                swap(grid[top][j], grid[bottom][j]);
            }
            
            // 換完一層了，指標往中間縮
            top++;
            bottom--;
        }
        
        return grid;
    }
};


