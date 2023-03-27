class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans[200][200];
        ans[0][0] = grid[0][0];
        for(int i=1;i<n;i++){
            ans[0][i] = grid[0][i] + ans[0][i-1];
        }
        for(int i=1;i<m;i++){
            ans[i][0] = ans[i-1][0] + grid[i][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(ans[i][j-1] > ans[i-1][j]){
                    ans[i][j] = ans[i-1][j] + grid[i][j];
                }
                else{
                    ans[i][j] = ans[i][j-1] + grid[i][j];
                }
            }
        }
        return ans[m-1][n-1];
    }
};
