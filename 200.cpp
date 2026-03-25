class Solution {
public:

    int m , n;
    void dfs(vector<vector<char>>& grid, int i,int j ){
        //邊界
        if(i<0 || j<0 || i>=m || j >=n) return;
        //這層有1，找四周
        if(grid[i][j] == '1'){
            grid[i][j] = '0';
        }
        //到0停下
        else{
            return;
        }
        //下層
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        //掃整張圖
        for(int i= 0;i<m;i++){
            for(int j = 0;j<n;j++){
                //看到 '1'，代表找到一座新島，cnt++
                if( grid[i][j] == '1'){
                    dfs(grid,i,j);
                    cnt++;
                }

            }
        }
        return cnt;
    }
};



//類似提 695 733 130 417
思路:
掃整張圖
如果看到一個還沒訪問過的 '1'
代表找到一座新島，cnt++
然後用 DFS 把這整塊島全部淹掉 / 標記掉
繼續掃下一格

//憂解
class Solution {
public:

    int m , n;
    void dfs(vector<vector<char>>& grid, int i,int j ){
        //邊界
        if(i<0 || j<0 || i>=m || j >=n) return;
        //這層有1，找四周
        if(grid[i][j] == '1'){
            grid[i][j] = '0';
        }
        //到0停下
        else{
            return;
        }
        //下層
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        //掃整張圖
        for(int i= 0;i<m;i++){
            for(int j = 0;j<n;j++){
                //看到 '1'，代表找到一座新島，cnt++
                if( grid[i][j] == '1'){
                    dfs(grid,i,j);
                    cnt++;
                }

            }
        }
        return cnt;
    }
};

  
