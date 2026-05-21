class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for(int a : nums1){
            s.insert(a);
        }
        int max_val = INT_MAX;
        for(int a : nums2){
            if(s.count(a)){
                max_val = min(max_val , a);
            }
        }
        return max_val == INT_MAX? -1 : max_val;
    }
};
