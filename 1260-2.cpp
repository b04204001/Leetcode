class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        if(k ==0)
            return grid;
        //while(k>0){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    int newi = (i+(j+k)/n)%m;
                    int newj = (j+k) %n;
                    ans[newi][newj] = grid[i][j];
                    /*if(i != m-1 && j == n-1){
                        ans[i+1][0]=grid[i][j];
                    }
                    else if(i == m-1 && j == n-1){
                        ans[0][0]=grid[i][j];
                    }
                    else{
                        ans[i][j+1]=grid[i][j];
                    }*/
                }
            }
            
            /*for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    grid[i][j]=ans[i][j];
                }
            }
            k--;
        }*/
        return ans;
    }
};
