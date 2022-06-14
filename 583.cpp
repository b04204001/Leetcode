20220614
  class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int>> lcs(m+1 , vector<int> (n+1,0 ));
        int ans;
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0 )
                    lcs[i][j] =0;
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(word1[i-1] == word2[j-1]){
                    lcs[i][j] = lcs[i-1][j-1]+1;
                }
                else{
                    lcs[i][j] = max( lcs[i][j-1] , lcs[i-1][j]);
                }
            }
        }
        ans = (m-lcs[m][n]) + (n-lcs[m][n]);
        return ans;
    }
};
