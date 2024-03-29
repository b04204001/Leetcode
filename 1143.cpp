class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        int A[m+1][n+1];
        for(int i=0;i<=m;i++){
            A[i][0] =0;
        }
        for(int i=0;i<=n;i++){
            A[0][i] =0;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(text1[i] == text2[j]){
                    A[i+1][j+1] = A[i][j] +1;
                }
                else{
                    A[i+1][j+1] = max (A[i][j+1] , A[i+1][j]);
                    /*if(A[i-1][j] > A[i][j-1]){
                        A[i][j] = A[i-1][j];
                    }
                    else{
                        A[i][j] = A[i][j-1];
                    }*/
                    
                }
            }
        }
        return A[m][n];
    }
};
