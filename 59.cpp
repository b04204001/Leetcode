//20220413 daily
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int flag[20][20] ={1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                flag[i][j] =0;
            }
        }
        int turn =0;
        int k=1;
        int i=0,j=0;
        while(k <= (n*n)){
            ans[i][j]= k;
            flag[i][j]=1;
            switch(turn){
                case 0:
                    j++;
                    break;
                case 1:
                    i++;
                    break;
                case 2:
                    j--;
                    break;
                case 3:
                    i--;
                    break;
            }
            if( flag[i][j] == 1){
                turn = (turn +1)%4;  
                int back =turn -1;
                switch(back){
                case 0:
                    i++;
                    break;
                case 1:
                    j--;
                    break;
                case 2:
                    i--;
                    break;
                case 3:
                    j++;
                    break;
                }
                switch(turn){
                case 0:
                    j++;
                    break;
                case 1:
                    i++;
                    break;
                case 2:
                    j--;
                    break;
                case 3:
                    i--;
                    break;
                }
            } 
            k++;
        }
        return ans;
    }
};
// || (i % n == (n-1)) || ( j % n == (n-1) ) 


