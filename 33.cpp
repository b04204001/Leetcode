class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        while(i<=j){
            int mid = i +(j-i)/2;
            if(target == nums[mid]) return mid;
            //左半邊轉點，右半遞增
            if(nums[i] > nums[mid]){
                //，比mid小，一定左半
                if(nums[mid] > target){
                    j = mid -1;
                }
                //比mid大，右半 + 左開頭 
                else{
                    //右半
                    if(target < nums[j]){
                        i = mid + 1;
                    }
                    //左開頭
                    else{
                        j = mid - 1;
                    }
                }
            }
            //右半邊轉點，左半遞增
            else{
                // 比mid大，在右半
                if(nums[mid] < target){
                    i = mid +1 ;
                }
                //左半 或 右半尾
                else{
                    // 比i大，右半
                    if(nums[i] > target){
                        i = mid + 1;
                    }
                    else{
                        j = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};
//優解

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
