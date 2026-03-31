class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;

        // Step 1: XOR 全部
        for (int num : nums) {
            x ^= num;
        }

        // Step 2: 找不同 bit
        int mask = x & (-x);

        int a = 0, b = 0;

        // Step 3: 分組 XOR
        for (int num : nums) {
            if (num & mask)
                a ^= num;
            else
                b ^= num;
        }

        return {a, b};
    }
};
