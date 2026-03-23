class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int leng =s.size();
        //前i個字母有幾種解法
        vector<int> dp( leng+1 ,0);
        //空字串
        dp[0] = 1;
        // 第一個字元不能是 '0'
        dp[1] = (s[0] != '0') ? 1 : 0;
        for(int i=2;i<=leng;i++){
            // 單一字元 可單獨解 = i-1 種解法
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            // 兩字元可以一起解 = i-2種解法
            int two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (two >= 10 && two <= 26) {
                dp[i] += dp[i - 2];
            }

        }
        return dp[leng];
    }
};

//DP ，看 I-1 和 I-2 
