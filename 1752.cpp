class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        for(int i = 1;i<n;i++){
            if(nums[i] < nums[i-1]){
                start = i;
                break;
            }
        }
        vector<int> new_ar = nums; 
        sort(new_ar.begin(),new_ar.end());
        if(start != 0){
            rotate(new_ar.begin(),new_ar.begin() + (n- start) ,new_ar.end());
        }
        for(int i = 0;i<n;i++){
            if(new_ar[i] != nums[i]) return false;
        }   
        return true;
    }
};
//最優解
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            // 使用 % n 讓陣列首尾相連循環比對
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }
        
        // 違反非遞減順序的次數不能超過 1 次
        return count <= 1;
    }
};
