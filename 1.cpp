class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            int temp = target - nums[i];
            if(nums[j] == temp){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }      
    }
    return ans;
}
};


//hash版本

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        for(int i=0;i<nums.size();i++){
            int diff = target - nums[i];
            if (seen.count(diff)){
                return {seen[diff], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};
