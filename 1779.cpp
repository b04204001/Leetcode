class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans=-1;
        int distance=10000;
        int n = points.size();
        for(int i=0;i<n;i++){
            int res;
            if(points[i][0]==x || points[i][1]==y){
                res = (abs(x - points[i][0]) + abs(y - points[i][1]));
                if(  distance >  res ){
                    distance =  res;
                    ans = i;
                }
            }
        }
        return ans;
    }
};
