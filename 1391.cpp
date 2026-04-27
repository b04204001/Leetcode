class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // 定義 6 種水管對應的移動方向 {dy, dx}
        // 1:左(0,-1),右(0,1) | 2:上(-1,0),下(1,0) | 3:左(0,-1),下(1,0)
        // 4:下(1,0),右(0,1) | 5:左(0,-1),上(-1,0) | 6:上(-1,0),右(0,1)
        vector<vector<pair<int, int>>> directions = {
            {}, // 佔位
            {{0, -1}, {0, 1}},  // 1
            {{-1, 0}, {1, 0}},  // 2
            {{0, -1}, {1, 0}},  // 3
            {{1, 0}, {0, 1}},   // 4
            {{0, -1}, {-1, 0}}, // 5
            {{-1, 0}, {0, 1}}   // 6
        };

        queue<pair<int, int>> q;
        q.push({0, 0});
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1) return true; // 到達終點

            // 嘗試從當前水管提供的兩個開口走出去
            for (auto& dir : directions[grid[r][c]]) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                // 1. 檢查邊界與是否走過
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    // 2. 關鍵判斷：下一個格子的水管，是否能接回「目前的格子」？
                    bool canConnectBack = false;
                    for (auto& backDir : directions[grid[nr][nc]]) {
                        if (nr + backDir.first == r && nc + backDir.second == c) {
                            canConnectBack = true;
                            break;
                        }
                    }

                    if (canConnectBack) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        return false;
    }
};
