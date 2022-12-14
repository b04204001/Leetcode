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
