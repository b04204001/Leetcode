class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        //撞到右側
        for(int i = 0;i<m;i++){
            for(int j = n-1;j>=0;j--){
                if(boxGrid[i][j] == '#'){
                    int k = j;
                    while( k + 1 < n && boxGrid[i][k+1] != '#' && boxGrid[i][k+1] != '*' ) k++;
                    boxGrid[i][j] = '.';
                    boxGrid[i][k] = '#';
                }
            }
        }
        //旋轉
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                ans[j][m - 1 - i] = boxGrid[i][j];
            }
        }
        return ans;
    }
};
