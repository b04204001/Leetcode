class Solution {
public:
    int BinSearch(vector<int>& nums , int l, int r){
        if (l == r) return nums[l];
        int mid = l + (r - l) /2;
        //中間比較大，代表最小在右半
        if(nums[mid] > nums[r]){
            return BinSearch(nums, mid + 1, r);
        }
        //中間比較小，代表最小在左半
        else{
           return BinSearch(nums, l, mid);
        }
    }
    int findMin(vector<int>& nums) {
        int n = nums.size(); 
        return BinSearch(nums,0,n-1);
    }
};

//優解
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            if (nums[l] < nums[r]) return nums[l];

            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return nums[l];
    }
};

