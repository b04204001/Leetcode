class Solution {
public:
    vector<int> countBits(int n) {
        // 陣列大小要開 n + 1，因為要包含 0
        vector<int> ans(n + 1, 0); 
        
        // 0 的 1 個數一定是 0，已經初始化好了，我們從 1 開始算
        for(int i = 1; i <= n; i++){
            // 核心神邏輯：
            // 當前數字的 1 個數 = (砍掉最後一位碼的數字的 1 個數) + (最後一位碼是不是 1)
            ans[i] = ans[i >> 1] + (i & 1);
        }
        
        return ans;
    }
};
