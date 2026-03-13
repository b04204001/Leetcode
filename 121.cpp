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


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price= prices[0];
        int profit = 0;
        for(int i=1;i<prices.size();i++){
            if (prices[i] < min_price){
                min_price = prices[i];
            }
            // < 更換買的價格
            else{
                profit = max( (prices[i] - min_price) , profit);
            }
        }
        return profit;
    }
};
