class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0; // 總和
        int tank = 0; // 探測車目前的油量
        int start = 0; // 預設起點從 0 開始

        for(int i = 0 ; i< n;i++){
            int diff = gas[i] - cost[i];
            sum += diff;
            tank += diff;
            if(tank < 0){
                start = i + 1;
                tank = 0;
            }
        }

        return (sum >= 0)? start : -1 ;
    }
};
