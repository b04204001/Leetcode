//直觀但RTE
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        //甚麼都不拿的base case
        dp[0] = 1;
        // 組合 vs 排列 ，coins在外，才不會重複計算， 在內 = 排列
        //每一輪只用一種coin去解決amount
        for (int c : coins) {
            for (int i = c; i <= amount; i++) {
              // 用c組合成i的方法是 i-c的方法數，因為i -c 的結果 + 一顆c就是i，
                dp[i] += dp[i - c];
            }
        }

        return dp[amount];
    }
};

//正解 倒數測資會爆炸
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int c : coins) {
            for (int i = c; i <= amount; i++) {
                dp[i] += dp[i - c];
            }
        }

        return (int)dp[amount];
    }
};
