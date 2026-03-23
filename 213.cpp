class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n,0); //包含頭
        vector<int> dp2(n,0); //不包含頭
        if(n == 1) return nums[0];
        dp1[0] = nums[0];
        dp1[1] = nums[0];
        dp2[0] = 0;
        dp2[1] = nums[1];
        for(int i = 2;i<n;i++){
            dp1[i] = max(dp1[i-1] , dp1[i-2] + nums[i]);
            dp2[i] = max(dp2[i-1] , dp2[i-2] + nums[i]);
        }
        return max(dp1[n-2], dp2[n-1]);
    }
};

//優解
改成解決 0~ n-2 vs 1~n-1，
class Solution {
public:
    int robLine(vector<int>& nums, int left, int right) {
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int i = left; i <= right; i++) {
            int cur = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        // 兩種情況：
        // 1. 偷 0 ~ n-2
        // 2. 偷 1 ~ n-1
        return max(robLine(nums, 0, n - 2), robLine(nums, 1, n - 1));
    }
};
