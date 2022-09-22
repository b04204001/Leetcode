class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto i:queries){
            int sum=0;
            nums[i[1]] = nums[i[1]] + i[0];
            for(int j=0;j<nums.size();j++){
                if(nums[j] %2 ==0){
                    sum += nums[j];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
