class Solution {
public:
    vector<int> getdigit(int n){
        vector<int> digit;
        while(n > 0){
            int d = n % 10;
            digit.push_back(d);
            n/=10;
        }
        reverse(digit.begin(),digit.end());
        return digit;
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto n : nums){
            vector<int> digit;
            digit = getdigit(n);
            for(auto d : digit){
                ans.push_back(d);
            }
        }
        return ans;
    }
};

//最優:
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int n : nums) {
            string s = to_string(n);
            for (char c : s) {
                ans.push_back(c - '0'); // 字元轉整數
            }
        }
        return ans;
    }
};
