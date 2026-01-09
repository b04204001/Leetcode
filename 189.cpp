class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        // 1. 處理 k 超過陣列長度的情況
        // 如果 n=7, k=8，其實等於旋轉 1 次。所以要取餘數。
        k = k % n; 
        
        // 2. 整體翻轉 (Reverse All)
        // [1,2,3,4,5,6,7] -> [7,6,5,4,3,2,1]
        reverse(nums.begin(), nums.end());
        
        // 3. 翻轉前 k 個 (Reverse First k)
        // [7,6,5 | 4,3,2,1] -> [5,6,7 | 4,3,2,1]
        // nums.begin() + k 代表第 k 個位置(不包含)
        reverse(nums.begin(), nums.begin() + k);
        
        // 4. 翻轉剩下的 (Reverse Rest)
        // [5,6,7 | 4,3,2,1] -> [5,6,7 | 1,2,3,4]
        reverse(nums.begin() + k, nums.end());
    }
};
