class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int cnt = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1]; // 右端點降序
            }
            return a[0] < b[0]; // 左端點升序
        });
        int laststart = intervals[0][0];
        int lastend = intervals[0][1];
        for(int i = 1;i<intervals.size();i++){
            if(intervals[i][0] >=laststart && intervals[i][1] <= lastend ){
                cnt--;
            }
            else{
                laststart =intervals[i][0];
                lastend = intervals[i][1];
            }
        }

        return cnt;
    }
};
