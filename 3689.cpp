class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int max_v = INT_MIN , min_v = INT_MAX ;
        long long ans = 0;
        for(int i = 0;i<n;i++){   
            if(nums[i] > max_v) max_v = nums[i];
            if(nums[i] < min_v) min_v = nums[i];
        }
        ans = (long long )(max_v - min_v ) * k;
        return ans;
    }
};
