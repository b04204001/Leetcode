class Solution {
public:
    void dfs(vector<vector<int>>& image , int i ,int j, int same, int color){
        int m = image.size();
        int n = image[0].size();
        if(i<0 || j <0 || i >=m || j >= n ) return;
        if(image[i][j] != same) return;
        image[i][j] = color;
        dfs(image,i-1,j,same,color);
        dfs(image,i+1,j,same,color);
        dfs(image,i,j-1,same,color);
        dfs(image,i,j+1,same,color);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        if (same == color) return image;
        int same = image[sr][sc];
        dfs(image,sr,sc,same,color);
        return image;
    }
};
