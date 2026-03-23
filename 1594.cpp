class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int MOD = 1e9 +7;
        vector<vector<long long>> maxproduct(r, vector<long long>(c, 0));
        vector<vector<long long>> minproduct(r, vector<long long>(c, 0));
        maxproduct[0][0] = grid[0][0];
        minproduct[0][0] = grid[0][0];
        for(int i = 1;i<r ;i++){
            maxproduct[i][0] = grid[i][0] * maxproduct[i-1][0];
            minproduct[i][0] = grid[i][0] * minproduct[i-1][0];
        }
        for(int j = 1;j<c;j++){
            maxproduct[0][j] = grid[0][j] * maxproduct[0][j-1];
            minproduct[0][j] = grid[0][j] * minproduct[0][j-1];
        }
        for(int i =1;i<r;i++){
            for(int j=1;j<c;j++){
                maxproduct[i][j] = max({(grid[i][j] * maxproduct[i][j-1]) , (grid[i][j] * maxproduct[i-1][j] ) , (grid[i][j] * minproduct[i][j-1]) , (grid[i][j] * minproduct[i-1][j] )});
                minproduct[i][j] = min({(grid[i][j] * maxproduct[i][j-1]) , (grid[i][j] * maxproduct[i-1][j] ) , (grid[i][j] * minproduct[i][j-1]) , (grid[i][j] * minproduct[i-1][j] )});
            }
        }
        return (maxproduct[r-1][c-1]>=0)? maxproduct[r-1][c-1]%MOD:-1;
    }
};

//筆記，因為有包含負數 : 所以要保存最大+最小，
// 記得用long long不含可能Overflow，
