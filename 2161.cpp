class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> equal;
        vector<int> greater;
        for(auto a : nums){
            if(a < pivot){
                less.push_back(a);
            }
            else if ( a == pivot){
                equal.push_back(a);
            }
            else{
                greater.push_back(a);
            }
        }
        vector<int> ans;
        for(auto a : less) ans.push_back(a);
        for(auto a : equal) ans.push_back(a);
        for(auto a : greater) ans.push_back(a);
        return ans;
    }
};
