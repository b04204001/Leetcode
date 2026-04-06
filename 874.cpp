class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int i = 0;
        int j = 0;
        int d = 0;

        set<pair<int,int>> obs;
        for (auto& o : obstacles) {
            obs.insert({o[0], o[1]});
        }
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int maxlen = 0;
        for( int c : commands){
            if( c == -1){
                d = (d + 1) % 4;
            }
            else if(c == -2){
                d = (d + 3) % 4;
            }
            else{
                for (int step=0;step <c;step++){
                    int nexti = i + dir[d][0];
                    int nextj = j + dir[d][1];

                    if (obs.count({nexti, nextj})) break; break;

                    i = nexti;
                    j = nextj;
                    maxlen = max(maxlen, i*i + j*j );
                }
                
            }
            
        }
        return maxlen;
    }
};
