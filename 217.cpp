class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> mp;
        for(int i=0;i<nums.size();i++){
            mp.insert( nums[i]);
        }
        if(mp.size() < nums.size()){
            return true;
        }
        else{
            return false;
        }
        
    }
};
