class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans=0;
        int n=nums.size();
        int index = n-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i] == val){
                nums[i] = nums[index];
                nums[index] = val;
                index--;
            }
            else{
                ans ++;
            }
        }
        return ans;
    }
};
