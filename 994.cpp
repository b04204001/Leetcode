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

        // 修正 2：把方向陣列移到最外面，全域只建立一次，省時省記憶體
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // 2. 開始 BFS 層序走訪
        while (!q.empty() && freshOranges > 0) {
            int size = q.size();
            minutes++; // 每擴散一層，時間加一分鐘

            for (int k = 0; k < size; k++) {
                auto [r, c] = q.front();
                q.pop();
                
                // 在 BFS 內部取代原本的四個 if
                for (auto& dir : dirs) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;
                    
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        freshOranges--; // 修正 1：改回原本宣告的變數名稱 freshOranges
                        q.push({nr, nc});
                    }
                }
            }
        }

        // 3. 判斷是否還有橘子無法被污染
        return freshOranges == 0 ? minutes : -1;
    }
};

