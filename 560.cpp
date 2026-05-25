class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        unordered_map<int,int> mp ;
        int sum = 0;
        mp[0] = 1; // 💡 關鍵補強：代表前綴和為 0 的初始狀態出現過 1 次
        for(auto n : nums){
            sum += n;
            
            //prefix sum = 前n像和
            if(mp.count(sum - k)){
                cnt += mp[sum-k];
            }
            mp[sum]++;
        }
        return cnt;
    }
};
