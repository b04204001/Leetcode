class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int ans= 999999;
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                int mn = matrix[i-1][j];
                if( j>0 && j<c-1){
                    mn = min(matrix[i-1][j-1],mn);
                    mn = min(mn , matrix[i-1][j+1]);
                }
                else if(j==0){
                    mn = min( mn , matrix[i-1][j+1] );
                }
                else if (j== (c-1)){ 
                    mn = min(matrix[i-1][j-1],mn );
                }
                matrix[i][j] += mn;
            }
        }
        for(int j = 0; j < c; j++){
            ans = min(ans, matrix[r - 1][j]);
        }
        return ans;
    }
};
