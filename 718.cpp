class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for(int i=0;i<nums1.size()-1;i++){
            for(int j=0;j<nums2.size()-1;j++){
                int k=0;
                while(nums1[i+k] == nums2[j+k]){
                    k++;
                    //if(i+k > nums1.size()-1 || j+k > nums2.size()-1 ) break;
                }
                ans = max(ans,k);
            }
        } 
        return ans;
    }
};
