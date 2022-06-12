20220613
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0, sum=0;
        unordered_set<int> st;
        int i=0,j=0;
        while(j<nums.size()){
            while(st.count(nums[j])>0){
                st.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            sum += nums[j];
            st.insert(nums[j++]);
            
            ans = max(sum, ans);
            
        }
        return ans;
    }
};
