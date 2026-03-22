class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> mzero(m,0);
        vector<int> nzero(n,0);
        //找出0的位置
        for(int i = 0;i<m;i++ ){
            for(int j =0;j<n;j++ ){
                if(matrix[i][j] == 0){
                    mzero[i] = 1;
                    nzero[j] = 1;
                }
            }
        }
        //設置0
        for(int i = 0;i<m;i++ ){
            if( mzero[i] != 0){
                for(int j=0;j<n;j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j =0;j<n;j++ ){
            if( nzero[j] != 0){
                for(int i=0;i<m;i++){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


//憂解 O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;
        // Step 1: 檢查第一列是否本來就有 0
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }
        // Step 2: 檢查第一行是否本來就有 0
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
        // Step 3: 用第一列與第一行做標記
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // Step 4: 根據標記，把內部元素設成 0
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 5: 如果第一列原本有 0，整列清 0
        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 6: 如果第一行原本有 0，整行清 0
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

