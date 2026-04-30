class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        // 初始化為 -1 表示路徑不通 m*n*k並填入-1
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(k + 1, -1)));

        // 初始位置
        int startCount = (grid[0][0] > 0 ? 1 : 0); // 假設條件是 > 0
        if (startCount <= k) {
            dp[0][0][startCount] = grid[0][0];
        }
        //開始DP
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int c = 0; c <= k; ++c) {
                    //不可走跳過
                    if (dp[i][j][c] == -1) continue;

                    // 往右走
                    if (j + 1 < n) {
                        int nextC = c + (grid[i][j + 1] > 0 ? 1 : 0);
                        if (nextC <= k) 
                            dp[i][j + 1][nextC] = max(dp[i][j + 1][nextC], dp[i][j][c] + grid[i][j + 1]);
                    }
                    // 往下走
                    if (i + 1 < m) {
                        int nextC = c + (grid[i + 1][j] > 0 ? 1 : 0);
                        if (nextC <= k)
                            dp[i + 1][j][nextC] = max(dp[i + 1][j][nextC], dp[i][j][c] + grid[i + 1][j]);
                    }
                }
            }
        }
        // 遍歷所有可能的成本 0 ~ k，找最大得分
        long long ans = -1; 
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m - 1][n - 1][c]);
        }

        return (int)ans;
    }
};
