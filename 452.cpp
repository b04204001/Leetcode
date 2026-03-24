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


//簡潔版本
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end());

        int cnt = 1;
        int end = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= end) {
                end = min(end, points[i][1]);
            } else {
                cnt++;
                end = points[i][1];
            }
        }

        return cnt;
    }
};
