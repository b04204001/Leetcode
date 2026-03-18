class Solution {
public:
    void Qsort(vector<int>& nums , int left , int right){
        if(left >= right) return ;
        int l = left + 1;
        int r = right;
        //挑選Pivot
        int mid = left + (right - left) / 2;
        
        // 我們把 left, mid, right 這三個位置的數字，排成「小 -> 中 -> 大」
        if (nums[left] > nums[mid]) swap(nums[left], nums[mid]);
        if (nums[left] > nums[right]) swap(nums[left], nums[right]);
        if (nums[mid] > nums[right]) swap(nums[mid], nums[right]);
        swap(nums[left], nums[mid]);
        int pivot  = nums[left];

        while(l<=r){
            //找到<pivot等交換
            while(l <= r && nums[r] > pivot){
                r--;
            }
            //找到>pivot等交換
            while(l <= r && nums[l] < pivot){
                l++;
            }
            if(l<=r){
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }
        swap(nums[left],nums[r]); 
        Qsort(nums,left,r-1);
        Qsort(nums,r+1,right);
        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        Qsort(nums,0,n-1);
        return nums;
    }
};
