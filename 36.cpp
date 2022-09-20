class Solution {
public:
    bool checksafe(vector<vector<char>>& board,int i,int j){
        bool temp = true;
        for(int k=0;k<board.size();k++){
            if(board[i][j] == board[k][j] && k !=i){
                temp = false;
            }
        }
        for(int k=0;k<board[0].size();k++){
            if(board[i][j] == board[i][k] && k != j){
                temp = false;
            }
        }
        int a=i-i%3;
        int b=j-j%3;
        for(int k=a;k<a+3;k++){
            for(int l=b;l<b+3;l++){
                if(k != i && l!= j){
                    if(board[i][j] == board[k][l]){
                        temp = false;
                    }
                }
            }
        }
        return temp;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int r = board.size(); 
        int c = board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j] != '.'){
                    bool safe = checksafe(board,i,j);
                    if(!safe){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
