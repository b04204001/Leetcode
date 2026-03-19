class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = left + (right - left)/2;
            if (target == nums[mid]){
                return mid;
            }
            //檢查是否是正常序列(左)
            if(nums[left] <=　nums[mid]){
                //確認正常看在哪
                if(target < nums[mid] && target >= nums[left]){
                    right = mid -1;
                }
                else{
                    left = mid +1;
                }
            }
            //檢查是否是正常序列(右)
            else{
                if(target > nums[mid] && target <= nums[right] ){
                    left = mid +1;
                }
                else{
                    right = mid -1;
                }
            }
           
        }
        return -1;
    }
};
