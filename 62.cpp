class Solution {
public:
    int uniquePaths(int m, int n) {
        int path[m][n];
        path[0][0] = 1;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i==0 && j ==0) continue;
                if(i == 0){
                    path[i][j] = path[i][j-1] ;
                }
                else if (j == 0){
                    path[i][j] = path[i-1][j] ;
                }
                else{
                    path[i][j] = path[i-1][j] + path[i][j-1];
                }
            }
        }
        return path[m-1][n-1];
    }
};


//優解
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};


//一維
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};
// m+n版本，挑選一條路走
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        int total = m + n - 2;
        int choose = min(m - 1, n - 1);

        for (int i = 1; i <= choose; i++) {
            ans = ans * (total - choose + i) / i;
        }

        return (int)ans;
    }
};
