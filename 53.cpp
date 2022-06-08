class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ans = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum = sum < 0 ? nums[i] : nums[i] + sum;
            ans = max(ans, sum);
        }
        return ans;
    }
};

