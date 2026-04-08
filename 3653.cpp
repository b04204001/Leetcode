//有overflow問題，要轉乘LONGLONG
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;
        const long long MOD = 1e9 + 7  ;
        for(auto q : queries){
            //[li, ri, ki, vi]
            int idx = q[0];
            while( idx <= q[1]){
                nums[idx] = (1LL * nums[idx] * q[3] ) % MOD ;
                idx += q[2];
            }
        }
        for( int n : nums){
            ans ^= n;
        }
        return ans;
    }
};
