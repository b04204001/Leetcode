class Solution {
public:
    int m;
    int n;
    void dfs(vector<vector<int>>& heights , vector<vector<bool>>& ocean ,int i,int j ,int prevHeight){
        if( i< 0 || j <0 || i>=m || j >=n ) return;
        if (ocean[i][j]) return;
        if (heights[i][j] < prevHeight) return;
        
        ocean[i][j] = true;

        dfs(heights ,ocean ,i+1 ,j , heights[i][j]);
        dfs(heights ,ocean ,i-1 ,j , heights[i][j]);
        dfs(heights ,ocean ,i ,j+1,heights[i][j]);
        dfs(heights ,ocean ,i ,j-1,heights[i][j]);
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(m , vector<bool>(n,false));
        vector<vector<bool>> atlantic(m , vector<bool>(n,false));
        for(int i =0;i<m;i++){
            dfs(heights ,pacific ,i ,0 ,heights[i][0] );
            dfs(heights ,atlantic ,i ,n-1 , heights[i][n-1]);
        }

        for(int j = 0 ;j < n ;j++){
            dfs(heights ,pacific ,0 ,j, heights[0][j]);
            dfs(heights ,atlantic ,m-1 ,j , heights[m-1][j]);
        }
        for(int i =0;i<m;i++){
            for(int j = 0 ;j < n ;j++){
                if(atlantic[i][j] == pacific[i][j] && pacific[i][j] == true){
                    vector<int> pair;
                    pair.push_back(i);
                    pair.push_back(j);
                    ans.push_back(pair);
                }
            }
        }
        return ans;
    }
};


//從海邊出法，哪格可以走到，做兩次DFS，從pacific和altantic，同時可以走道就是答案
class Solution {
public:
    // 紀錄矩陣大小
    int m, n;
    // 四個方向：下、上、右、左
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    // DFS：從海邊反向往內陸走
    // vis[x][y] = true 代表這格「可以流到這片海」
    void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<bool>>& vis) {
        vis[x][y] = true;

        // 嘗試往四個方向擴展
        for (auto& d : dir) {
            int nx = x + d[0];
            int ny = y + d[1];

            // 1. 越界就不能走
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

            // 2. 已經走過就不用重複
            if (vis[nx][ny]) continue;

            // 3. 反向思考：
            // 如果原本水能從高處/等高流到低處，
            // 那從海邊反推時，只能走到「更高或等高」的格子
            if (heights[nx][ny] >= heights[x][y]) {
                dfs(heights, nx, ny, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        // pac[i][j] = 這格能流到 Pacific
        // atl[i][j] = 這格能流到 Atlantic
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        // Pacific 在「上邊界 + 左邊界」
        // Atlantic 在「下邊界 + 右邊界」

        // 從每一列的最左 / 最右開始做 DFS
        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, pac);       // 左邊界 -> Pacific
            dfs(heights, i, n - 1, atl);   // 右邊界 -> Atlantic
        }

        // 從每一欄的最上 / 最下開始做 DFS
        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, pac);       // 上邊界 -> Pacific
            dfs(heights, m - 1, j, atl);   // 下邊界 -> Atlantic
        }

        // 同時能到 Pacific 和 Atlantic 的格子，就是答案
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
