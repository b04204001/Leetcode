class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        // 數字最大只可能是 n-1，若長度不足 2 則不合法
        if (n < 2) return false; 
        
        // 建立大小為 n 的計數器，初始值為 0
        vector<int> count(n, 0); 
        
        for (int d : nums) {
            // 好陣列的數字必須在 1 到 n-1 之間
            if (d < 1 || d > n - 1) return false;
            count[d]++;
        }
        
        // 檢查 1 到 n-2 是否都剛好出現 1 次
        for (int i = 1; i < n - 1; i++) {
            if (count[i] != 1) return false;
        }
        
        // 檢查最大值 n-1 是否剛好出現 2 次
        return count[n - 1] == 2;
    }
};
