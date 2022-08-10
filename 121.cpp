class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1){
            return 0;
        }
        int minValue=prices[0];
        int res=0;
        for(int i=0; i<n; i++){
            res=max(res, prices[i]-minValue);
            minValue=min(minValue, prices[i]);
        }
        return res;
    }
};
