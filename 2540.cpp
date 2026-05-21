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

//最優解 雙指標
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int n = nums1.size();
        int m = nums2.size();
        int max_val = INT_MAX;
        while(i<n && j <m){
            if(nums1[i] == nums2[j]){
                max_val = min(max_val , nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j]){
                j++;
            }
            else {
                i++;
            }
        }
        return max_val == INT_MAX? -1 : max_val;
    }
};
