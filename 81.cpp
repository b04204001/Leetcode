class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        while(i <= j){
            int mid = i + (j-i)/2;
            if(nums[mid] == target) return true;
            // 關鍵：當三者相等時，無法判斷哪邊有序，將兩端縮小範圍
            if (nums[i] == nums[mid] && nums[mid] == nums[j]) {
                i++;
                j--;
            }
            else if (nums[i] <= nums[mid]) {
                // target 落在左半邊的有序區間內
                if (nums[i] <= target && target < nums[mid]) {
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }
            }
            // 右半邊有序
            else {
                // target 落在右半邊的有序區間內
                if (nums[mid] < target && target <= nums[j]) {
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
            }
        }
        return false;
    }
};
