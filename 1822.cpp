class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans =0;
        int neg =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                neg++;
            }
            if(nums[i]==0){
                ans =0;
                return ans;
            }
        }
        if(neg %2 ==0){
            ans =1;
        }
        else{
            ans =-1;
        }

        return ans;
    }
};
