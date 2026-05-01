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


int removeElement(int* nums, int numsSize, int val) {
    int j = 0;
    for(int i = 0 ; i<numsSize;i++){
        if(nums[i] != val){
            nums[j] = nums[i]; 
            j++;
        }
    }
    return j;
}
