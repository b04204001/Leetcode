class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maxc =n/2;
        int maxi;
        map < int, int> count;
        for(auto x: nums){
            count[x]++;
        }
        for(auto i:count){
            if( i.second > maxc){
                maxi = i.first;
            }
        }
        return maxi;
    }
};
