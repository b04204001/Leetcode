//20220413 daily
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int flag[22][22]={0};
        int turn =0;
        int k=1;
        int i=0, j=0;
        int back;
        for(int p=0;p<=21;p++){
            for(int q=0;q<=21;q++){
                if(p>=1 && p<= n && q>=1 && q<=n)
                    flag[p][q] =0;
                else
                    flag[p][q] =1;

            }
        }
        while (k <= (n*n)){
            ans[i][j] = k;
            flag[i+1][j+1] =1;
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
            if( flag[i+1][j+1] == 1){
                back =turn;
                turn = (turn +1)%4;  
                switch(back){
                case 0:
                    j--;
                    break;
                case 1:
                    i--;
                    break;
                case 2:
                    j++;
                    break;
                case 3:
                    i++;
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
