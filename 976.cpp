class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=n-3;i>=0;i--){
            if(nums[i+2]< nums[i+1] + nums[i]){
                return (nums[i] + nums[i+1] + nums[i+2]);
            }
        }
        return ans;
    }
};

