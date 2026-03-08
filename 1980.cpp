class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        //對角線不同法: 地i位跟第i個字串不同，這樣對於每個字串都有一個位置跟他不同
        int n = nums.size();
        string ans="";
        for(int i=0 ;i<n; i++){
            char a = nums[i][i];
            if(a =='0'){
                ans += '1';
            }
            else{
                ans += '0';
            }
        }
        return ans;
    }
};
