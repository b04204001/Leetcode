//自己寫法
class Solution {
public:
    void dfs(vector<vector<int>>& grid , int i , int j, int siz){
        int m = grid.size();
        int n = grid[0].size();
        //邊界
        if( i < 0 || j < 0 || i >= m || j >=n ) return;
        //這層
        if(grid[i][j] != 1) return;

        grid[i][j] = siz;
        //下層
        dfs(grid,i-1,j,siz);
        dfs(grid,i+1,j,siz);
        dfs(grid,i,j-1,siz);
        dfs(grid,i,j+1,siz);

        return ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int count = 2;
        
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j,count);
                    count++;
                }
            }
        }
        vector<int> area(count,0);
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if( grid[i][j] != 0){
                    area[grid[i][j]]++;
                }
            }
        }
        for(int k = 2; k < count;k++){
            if(area[k] > ans ){
                ans = area[k];
            }
        }
        return ans;
    }
};
//比較慢

//憂解
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        // 邊界
        if (i < 0 || j < 0 || i >= m || j >= n) return 0;

        // 不是陸地
        if (grid[i][j] != 1) return 0;

        // 標記已訪問
        grid[i][j] = 0;

        // 自己這格算 1
        return 1
             + dfs(grid, i - 1, j)
             + dfs(grid, i + 1, j)
             + dfs(grid, i, j - 1)
             + dfs(grid, i, j + 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j);
                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};
