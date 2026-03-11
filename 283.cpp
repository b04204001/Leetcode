class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n= nums.size();
        int j = 0; 
        for(int i=0;i<n;i++){
            //非0交換，代表0時j會停在0處，之後不斷把非0往前放
            if(nums[i] != 0){
                swap(nums[i],nums[j++]);
            }
        }
    }
};
