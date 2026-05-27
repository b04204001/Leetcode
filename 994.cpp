class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        int minute = 0;
        for(int i = 0 ;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if( grid[i][j] == 1) fresh++;
            }
        }
        if (fresh == 0) return 0;

        while(!q.empty() && fresh > 0){
            int levelsize = q.size();
            for(int i = 0;i<levelsize;i++){
                auto [r,c] = q.front();
                q.pop();
                if(r-1 >= 0 && grid[r-1][c] == 1){
                    grid[r-1][c] = 2;
                    fresh--;
                    q.push({r-1,c});
                }
                if(r +1 < m &&grid[r+1][c] == 1){
                    grid[r+1][c] = 2;
                    fresh--;
                    q.push({r+1,c});
                }
                if(c-1 >= 0 &&grid[r][c-1] == 1){
                    grid[r][c-1] = 2;
                    fresh--;
                    q.push({r,c-1});
                }
                if(c+1 < n && grid[r][c+1] == 1){
                    grid[r][c+1] = 2;
                    fresh--;
                    q.push({r,c+1});
                }
            }
            minute++;
        }
        return fresh == 0 ? minute : -1;
    }
};
//正解
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;
        int minutes = 0;

        // 1. 統計新鮮橘子數量，並將初始腐爛的橘子加入佇列
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        // 如果一開始就沒有新鮮橘子，直接返回 0
        if (freshOranges == 0) return 0;

        // 方向陣列：上、下、左、右
        vector<int> dirs = {-1, 0, 1, 0, -1};

        // 2. 開始 BFS 層序走訪
        while (!q.empty() && freshOranges > 0) {
            int size = q.size();
            minutes++; // 每擴散一層，時間加一分鐘

            for (int k = 0; k < size; k++) {
                auto [r, c] = q.front();
                q.pop();

                // 檢查四個方向
                for (int d = 0; d < 4; d++) {
                    int nr = r + dirs[d];
                    int nc = c + dirs[d + 1];

                    // 判斷是否越界或是新鮮橘子
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // 變成腐爛橘子
                        q.push({nr, nc}); // 加入佇列以供下一分鐘擴散
                        freshOranges--;   // 新鮮橘子減少
                    }
                }
            }
        }

        // 3. 判斷是否還有橘子無法被污染
        return freshOranges == 0 ? minutes : -1;
    }
};
