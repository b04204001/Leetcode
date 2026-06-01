class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int total_cost = 0;
        sort(cost.begin(),cost.end());
        int cnt = 1;
        for(int i=cost.size()-1;i>=0;i--){
            if(cnt % 3 != 0){
                total_cost += cost[i];
            }
            cnt++;
        }
        return total_cost;
    }
};
