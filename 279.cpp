class Solution {
public:
    int numSquares(int n) {
        vector<int> sq ;
        int i = 1;
        while( n >= (i*i)){
            sq.push_back(i*i);
            i++;
        }
        vector<int> dp(n+1,n+1);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(int s : sq){
                if( i - s >= 0){
                    dp[i] = min(dp[i],dp[i-s] + 1);
                }
            }
        }
        return (dp[n] == n+1)? -1 : dp[n];
    }
};

//類似322 DP解法
