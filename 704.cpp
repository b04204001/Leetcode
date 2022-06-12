TLE
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high = nums.size()-1;
        int ans=-1;
        while(low <=high){
            int mid = (high+low)/2;
            if( target == nums[mid]){
                ans = mid;
                break;
            }
            else if( target > nums[mid]){
                low = mid;
            }
            else{
                high = mid;
            }
        }

        return ans;
    }
};
