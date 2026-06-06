class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> profix(n,0);
        vector<int> suffix(n,0);
        for(int i = 1;i<n;i++){
            profix[i] = profix[i-1] + nums[i-1];
        }
        for(int i = n-2;i>=0;i--){
            suffix[i] = suffix[i+1] + nums[i+1];
        }
        vector<int> diff(n,0);
        for(int i=0;i<n;i++){
            diff[i] = abs(profix[i] - suffix[i]);
        }
        return diff;
    }
};
