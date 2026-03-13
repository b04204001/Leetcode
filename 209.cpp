class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //1.雙指標
        int l = 0;
        int r = 0;
        int sum = 0;
        int min_length = INT_MAX;
        //2.開掃
        for(r = 0; r < nums.size();r++){
            sum += nums[r];
            while(sum >= target){
                min_length = min(min_length, r - l + 1);
                sum-=nums[l];
                l++;
            }

        }
        return min_length == INT_MAX ?  0 : min_length;
    }
};
