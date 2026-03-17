class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int a : nums){
            mp[a]++;
        }
        for(int i =0;i<n;i++){
            if(mp[i] == 0){
                return i;
            }
        }
        return n;
    }
};

//憂解 預計總和 - 實際總和
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // 算出 0 到 n 的完美總和
        int expectedSum = n * (n + 1) / 2;
        
        int actualSum = 0;
        for(int num : nums){
            actualSum += num;
        }
        
        // 兩者相減就是消失的數字
        return expectedSum - actualSum;
    }
};


//憂解 預計總和 - 實際總和
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size(); // 先把缺的那個 n 放進去
        
        for(int i = 0; i < nums.size(); i++){
            // 把 Index 和 Value 全部 XOR 起來
            missing ^= i ^ nums[i]; 
        }
        
        return missing;
    }
};
