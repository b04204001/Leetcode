class Solution {
public:
    int BinSearch(vector<int>& nums , int l, int r){
        if (l == r) return nums[l];
        int mid = l + (r - l) /2;
        int lmin;
        int rmin;
        //中間比較大，代表最小在右半
        if(nums[mid] > nums[r]){
            lmin = BinSearch(nums,mid+1,r);
        }
        //中間比較小，代表最小在左半
        else{
            rmin = BinSearch(nums,l,mid);
        }
        return min(lmin,rmin);
    }
    int findMin(vector<int>& nums) {
        int n = nums.size(); 
        return BinSearch(nums,0,n-1);
    }
};
