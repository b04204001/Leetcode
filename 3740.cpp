class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int , vector<int>> mp;
        int target = -1;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        bool have = false;
        int mind = INT_MAX;
        //假設 i < j < k ->  j - i + k - j + k - i = 2k-2i
        for(auto& [val, indices] : mp ){
            if( indices.size() >= 3){
                have = true;
                for(int i = 0 ; i < indices.size() - 2 ; i++){
                    int j = indices[i];
                    int k = indices[i+2];
                    mind = min(mind, 2*(k - j) );
                }
            }
        }
        return have ? mind : -1;
    }
};
