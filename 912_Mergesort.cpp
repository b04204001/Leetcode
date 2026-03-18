class Solution {
public:

    void MergeSort(vector<int>& nums ,vector<int>& temp, int left , int right){
        if (left >= right) return;
        //1. 拆分一半
        int mid = (left + right) /2;
        MergeSort(nums ,temp,left , mid);
        MergeSort(nums ,temp,mid+1 , right);

        //2. 合併，雙指針，小的先放入最後
        int l = left;
        int r = mid+1;
        int idx = left;
        //同時比較
        while(l <= mid && r <= right){
            if(nums[l] >= nums[r] ){
                temp[idx++] = nums[r++];
            }
            else{
                temp[idx++] = nums[l++];
            }
        }
        //剩單邊直接填入
        while(l <= mid){
            temp[idx++] = nums[l++];
        }
        while(r <= right){
            temp[idx++] = nums[r++];
        }
        for(int i = left; i <= right; i++){
            nums[i] = temp[i];
        }
        return;
    }


    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, 0);
        //Quicksort(nums,0,n-1);
        MergeSort(nums,temp,0,n-1);
        return nums;
    }
};
