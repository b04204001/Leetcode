class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m = landStartTime.size();
        int n = waterStartTime.size();
        int time = INT_MAX;
        //1.
        int land_end = INT_MAX;
        for(int i = 0; i < m;i++){
            land_end = min(land_end, landStartTime[i] + landDuration[i]);
        }
        for(int j = 0;j<n;j++){
            int end = max(land_end, waterStartTime[j]) + waterDuration[j];
            time = min(time, end);
        }
        //2.
        int water_end = INT_MAX;
        for(int j = 0;j<n;j++){
            water_end = min(water_end,waterStartTime[j] + waterDuration[j]);
        }
        for(int i = 0; i < m;i++){
            int end = max(water_end, landStartTime[i]) + landDuration[i];
            time = min(time, end);
        }
        return time;
    }
};
