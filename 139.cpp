class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //因為要查詢所以用hash 
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        //前 i 個字元能不能被成功切分
        vector<bool> dp(n + 1, false);

        dp[0] = true;
        //前i個字元結果
        for (int i = 1; i <= n; i++) {
            //最後一段開始位置
            for (int j = 0; j < i; j++) {
                //最後一段開始是j，所以先確認前j個結果，正確再看 從j開始到i的結果是否在dict中
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
