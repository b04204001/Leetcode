class Solution {
public:
    int rob(vector<int>& nums) {
    int n = nums.size();
    int max[100];
    if(n==1) return nums[0];
    max[0] =nums[0];
    if(nums[1]>nums[0]){
        max[1] = nums[1];
    }
    else{
        max[1] = nums[0];
    }

    for(int i = 2 ; i < n ; i++){
        //最大金額   = Max(現在金額+前前一棟最大金額 ， 前一棟最大金額)
        if( (nums[i] + max[i-2]) > max[i-1]   ){
            max[i] = nums[i] + max[i-2];
        }
        else{
            max[i] = max[i-1];
        }
    }
        return max[n-1];
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        //指闖一晚
        dp[0] = nums[0];
        if( n == 1) return dp[0];
        dp[1] = max( dp[0], nums[1]);
        for(int i=2;i<n;i++){
            dp[i] = max( dp[i-1]  , dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
};

//O(1)版本
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int cur = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};
