class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int length = 0;
        for(int n : num_set){
            //是起點
            if(!num_set.count(n - 1)){
                int curr_n = n;
                int curr_len = 1;
                //去找長度
                while(num_set.count(curr_n +1)){
                    curr_n++;
                    curr_len++;
                }
                
                length = max(length ,curr_len );
            }
        }
        return length;
    }
};
