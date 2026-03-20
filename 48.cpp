class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //1. 主對角線」對摺
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0;i<row;i++){
            for(int j =i;j<col;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //2. 把每一列 (Row)「左右水平翻轉」 (Reverse)
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(),matrix[i].end() );
        }
        return ;
    }
};
