//TLE
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        int n = nums.size();
        for(auto q: queries){
            int min_d = INT_MAX;
            for(int i=0;i<n;i++){
                if(nums[i] == nums[q] && i != q){
                    int left = abs(i - q) % n;
                    int right = n - abs(i - q ) % n;
                    if(min_d > left){
                        min_d = left;
                    }
                    if(min_d > right){
                        min_d = right;
                    }
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

