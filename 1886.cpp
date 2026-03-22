class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<bool> r(4,true);
        int n = mat.size();
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                //0 不轉
                if(mat[i][j]!=target[i][j]) r[0]=false;
                //90 j ->變成 row，另一邊逆轉 i -> n-1 - i
                if(mat[i][j]!=target[j][n-1-i]) r[1]=false;
                //180   n-1-i -> row，另一邊逆轉 j -> n-1-j
                if(mat[i][j]!=target[n-1-i][n-1-j]) r[2]=false;
                //270 n-1-j ->row， 另一邊逆轉 n-1-i ->i
                if(mat[i][j]!=target[n-1-j][i]) r[3]=false;
            }
        }
        return r[0] || r[1] || r[2] || r[3];
    }
};
