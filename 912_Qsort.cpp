class Solution {
public:
    void Qsort(vector<int>& nums , int left , int right){
        if(left >= right) return ;
        int l = left;
        int r = right;
        //挑選Pivot
        int pivot  = nums[left];

        while(l<r){
            //找到<pivot等交換
            while(l < r && nums[r] > pivot){
                r--;
            }
            //找到>pivot等交換
            while(l < r && nums[l] <= pivot){
                l++;
            }
            if(l<r){
                swap(nums[l], nums[r]);
            }
        }
        swap(nums[left],nums[l]); 
        Qsort(nums,left,l-1);
        Qsort(nums,l+1,right);
        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        Qsort(nums,0,n-1);
        return nums;
    }
};
