//TLE
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int , vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto q: queries){
            if(!mp.contains(nums[q])) continue;
            int min_d = INT_MAX;
            for(auto i : mp[nums[q]]){
                if(i != q){
                    int left = abs(i - q) % n;
                    int right = n - abs(i - q ) % n;
                    if(min_d > left){
                        min_d = left;
                    }
                    if(min_d > right){
                        min_d = right;
                    }
                    if( min_d == 1) break;
                }
            }
            if(min_d == INT_MAX){
                min_d = -1;
            }
            ans.push_back(min_d);
        }
        return ans;
    }
};
