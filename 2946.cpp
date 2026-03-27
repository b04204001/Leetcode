class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> shiftmat(m,vector<int>(n,0));
        if( k % n == 0 ) return true;
        k %= n;
        for(int i = 0;i<m;i++){
            for(int j = 0; j<n;j++){
                //偶數 左移
                if ( i % 2 == 0){
                    shiftmat[i][j] = mat[i][ (j+k)%n];
                }
                //奇數 右移
                else{
                    shiftmat[i][j] = mat[i][(j-k+n) % n];
                }
                
            }
        }
        //確認
        for(int i = 0;i<m;i++){
            for(int j = 0; j<n;j++){
                if( shiftmat[i][j] != mat[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
};
//優解
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k %= n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    // 偶數列左移 k
                    if (mat[i][j] != mat[i][(j + k) % n]) {
                        return false;
                    }
                } else {
                    // 奇數列右移 k
                    if (mat[i][j] != mat[i][(j - k + n) % n]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
