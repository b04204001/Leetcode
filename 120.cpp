// DP有看答案
20220613
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> ans = triangle[n-1];
        
        for(int i =n-2;i>=0;i--){
            // 從倒數第二層往上
            for(int j=0;j<triangle[i].size();j++){
                //每一層自己左右最小的累積再往上爬
                  ans[j] = triangle[i][j] + min(ans[j],ans[j+1]);        
            }
        }
        return ans[0];
    }
};
