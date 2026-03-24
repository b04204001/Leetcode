class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> last = intervals[0];
        for(int i =1;i<n;i++){
            if(intervals[i][0] < last[1] ){
                if(intervals[i][1]<last[1]){
                    last = intervals[i];
                }
                cnt++;
            }
            else{
                last = intervals[i];
            }
        }
        return cnt;
    }
};

//概念上是 遇到重疊保留區段短的，長的刪掉，才能山的少，所以專注看區段尾巴，因為sort過，所以只看尾巴
