class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // nums1 最後一個有效元素的 index
        int j = n - 1; // nums2 最後一個元素的 index
        int k = m + n - 1; // nums1 整個陣列最後一個位置
        
        // 從後面開始比，誰大就放最後面
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        // 如果 nums2 還有剩，把它們補進去
        // (如果是 nums1 有剩，不用動，因為它們本來就在 nums1 裡面且已經排好了)
        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
