class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int target ,int color) {
        int m = image.size();
        int n = image[0].size();
        if(i >= m || j>= n || i<0 || j <0) return;
        if(image[i][j] == color) return;
        if(image[i][j] != target ) return;
        image[i][j]=color;
        dfs(image,i-1,j,target,color);
        dfs(image,i+1,j,target,color);
        dfs(image,i,j-1,target,color);
        dfs(image,i,j+1,target,color);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};

//解答
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
        int same = image[sr][sc];
        if (same == color) return image;
        dfs(image,sr,sc,same,color);
        return image;
    }
};
