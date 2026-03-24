class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //因為要查詢所以用hash 
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        //前 i 個字元能不能被成功切分
        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                //因為前j已經確認是word，所以要確認 i-j長度的字串( j ~ i)
                if (dp[j] && st.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

//
