class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        // C++ 的 int 是 32 個 bit，我們一個一個 bit 檢查
        for (int i = 0; i < 32; i++) {
            int sum = 0; // 統計第 i 個 bit 有幾個 1
            
            for (int num : nums) {
                // 把 num 往右移 i 位，跟 1 做 AND 運算，就能取出第 i 個 bit 是 0 還是 1
                sum += (num >> i) & 1; 
            }
            
            // 如果加起來不是 3 的倍數，代表答案的這一個 bit 是 1
            if (sum % 3 != 0) {
                // 把 1 往左移 i 位，塞回我們的答案裡 (使用 OR 運算)
                ans |= (1 << i); 
            }
        }
        return ans;
    }
};
