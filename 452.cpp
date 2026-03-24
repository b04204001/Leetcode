class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int cnt = 0;
        int n = points.size();
        sort(points.begin(),points.end());
        //發射區間
        vector<int> target = points[0];
        //從第一個區間開始找重疊，搜完沒有才發射
        for(int i = 1;i<n;i++){
            //有重疊可以連爆
            if(target[1] >= points[i][0] ){
                //找尋新的target區間是否重疊先不射
                if( points[i][1] < target[1]){
                    target[1] = points[i][1];
                }
                if( points[i][0] > target[0]){
                    target[0] = points[i][0];
                }
            }
            //無重疊，把舊的射掉，新的放上
            else{
                target = points[i];
                cnt++;
            }   
        }
        //補上最後一發射掉
        cnt++;
        return cnt;
    }
};
