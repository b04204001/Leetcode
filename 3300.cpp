class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        vector<string> num ;
        for(auto a : nums){
            string b = to_string(a);
            num.push_back(b);
        }
        int min_val = INT_MAX;
        for(auto c : num){
            int sum = 0;
            for(int j = 0; j < c.length();j++){
                sum += c[j] - '0';
            }
            min_val = min(min_val , sum);
        }

        return min_val;
    }
};

//更好做法
class Solution {
public:
    int minElement(vector<int>& nums) {
        int min_val = INT_MAX;
        
        for (int num : nums) {
            int sum = 0;
            // 使用數學運算拆解每一位數
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            min_val = min(min_val, sum);
        }
        
        return min_val;
    }
};
