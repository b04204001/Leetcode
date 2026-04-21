class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int max_dis = 0;
        int i = 0;
        int j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        while(i < n1 && j < n2){
            if(nums1[i] <= nums2[j] ){
                max_dis = max(max_dis , j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return max_dis;
    }
};
