// 56解法
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<int> last= intervals[0];
        for(int i = 1 ;i <intervals.size();i++){
            //前尾 > 後頭
            if( last[1] >= intervals[i][0]){
                last[1] = max(last[1], intervals[i][1]);
            }
            else{
                ans.push_back(last);
                last = intervals[i];
            }
        }
        ans.push_back(last);
        return ans;
    }
};

//優解
