class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dis(m,vector<int>(n,0));
        vector<vector<bool>> index(m,vector<bool>(n,false));
        queue<pair<int, int>> q;
        int numofone = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0; j <n;j++){
                if(mat[i][j] == 0) {
                    q.push({i,j});
                    index[i][j] = true;
                }
                if(mat[i][j] == 1) {
                    dis[i][j] = INT_MAX;
                }
            }
        }
        vector<pair<int,int>> dir{{-1,0} , {0,1} , {1,0} , {0,-1}};
        bool findzero = false;
        int distance = 0;

        while(!q.empty() ){
            int levelsize = q.size();
            distance++;
            for(int i = 0;i<levelsize;i++){
                auto [r,c] = q.front();
                q.pop();
                for(auto& d : dir){
                    int next_r = r + d.first;
                    int next_c = c + d.second;
                    if( next_r < 0 || next_r >= m || next_c < 0 || next_c >=n ) continue;

                    if( mat[next_r][next_c] == 1){
                        if(!index[next_r][next_c]){
                            q.push({next_r,next_c});
                            index[next_r][next_c] = true;
                            dis[next_r][next_c] = distance;
                        }
                    }
                  
                }

            }
        }
        return dis;
    }
};

//憂解
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // 將 1 的地方初始化為 -1，代表尚未訪問
        vector<vector<int>> dis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    dis[i][j] = -1; // -1 代表這個 1 還沒被 BFS 走到
                }
            }
        }
        
        vector<pair<int, int>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int distance = 0;

        while(!q.empty()){
            int levelsize = q.size();
            distance++;
            for(int i = 0; i < levelsize; i++){
                auto [r, c] = q.front();
                q.pop();
                
                for(auto& d : dir){
                    int next_r = r + d.first;
                    int next_c = c + d.second;
                    
                    // 邊界檢查
                    if(next_r < 0 || next_r >= m || next_c < 0 || next_c >= n) continue;

                    // 如果是 -1，代表這是第一次被走到的 1（即最短距離）
                    if(dis[next_r][next_c] == -1){
                        dis[next_r][next_c] = distance;
                        q.push({next_r, next_c});
                    }
                }
            }
        }
        return dis;
    }
};
