class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxp(n,1);
        vector<int> minp(n,1);
        if(nums[0] != 0){
            maxp[0] = nums[0];
            minp[0] = nums[0];
        }
        int ans = nums[0];
        for(int i = 1;i<n;i++){
            if(nums[i] !=0){
                maxp[i]= max({maxp[i-1] * nums[i] , minp[i-1] * nums[i] , nums[i]});
                minp[i]= min({maxp[i-1] * nums[i] , minp[i-1] * nums[i] , nums[i]});
            }
            else{
                maxp[i] = nums[i];
                minp[i] = nums[i];
            }
            if(maxp[i] > ans) ans= maxp[i];
        }

        return ans;
    }
};
