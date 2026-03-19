class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        vector<int> sumX(col,0);
        vector<int> sumY(col,0);
        for(int i =0 ;i<row;i++){
            int nX = 0;
            int nY = 0;
            for(int j =0 ;j<col;j++){
                if(grid[i][j] == 'X') nX++;
                else if(grid[i][j] == 'Y') nY++;
                sumX[j] += nY;
                sumY[j] += nX;
                if(sumX[j] > 0 && sumX[j] == sumY[j] ) ans+=1;
            }
        }
        return ans;
    }
};
