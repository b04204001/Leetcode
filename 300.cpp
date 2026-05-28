class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // 處理空陣列
        
        // 每個元素初始的 LIS 長度都是 1
        vector<int> dp(n, 1); 
        int max_len = 1;      
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // 如果當前元素大於前面的元素，嘗試更新 dp[i]
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_len = max(max_len, dp[i]); // 記錄全域最大長度
        }
        return max_len;
    }
};
