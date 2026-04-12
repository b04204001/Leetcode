class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map <int , vector<int>> mp;
        vector<int> candidate ;
        for(int i = 0; i < nums.size();i++){
            mp[nums[i]].push_back(i);
            if(mp[nums[i]].size() == 3) candidate.push_back(nums[i]);
        }
        bool have = false;
        int min_d = INT_MAX;
        for(auto& [val,indices ] : mp){
            for(auto c: candidate){
                if( c == val){
                    for(int i = 0;i<indices.size()-2;i++){
                        int j = indices[i];
                        int k = indices[i+2];
                        min_d = min( min_d , 2 * ( k - j) );
                        have = true;
                    }
                }
            }
        }

        return have ? min_d : -1;
    }
};
