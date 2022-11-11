class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        for(auto x:nums){
            if(count ==0){
                nums[count++] = x;
            }
            else{
                if( x > nums[count-1]) {
                    nums[count++] = x;
                }
            }
        }
        return count;
    }
};
