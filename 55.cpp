class Solution {
public:
    bool canJump(vector<int>& nums) {
        int g = nums.size() - 1;
        for (int i =g-1;i>=0;i--){
            if(nums[i] + i >= g ){
                g = i;
            }
        }
        return g==0;
    }
};
