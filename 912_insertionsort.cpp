class Solution {
public:
    void InsertionSort(vector<int>& nums , int left , int right){
        if (left >= right) return;
        for(int i = left + 1 ;i <= right;i++){
            int j = i - 1;
            int target = nums[i];
            while( j >= left && nums[j] > target ){
                nums[++j] = nums[j];
                j--;
            }
            nums[j+1] = target;
        }
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        InsertionSort(nums,0,n-1);
        return nums;
    }
};
