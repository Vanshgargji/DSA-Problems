class Solution {
public:
    int m , n;

    void dfs(int row, int col, vector<vector<int>> &image2, vector<vector<int>> &vis, int color, int val){
        vis[row][col] = 1;
        image2[row][col] = color;

        if(col-1 >= 0 && image2[row][col-1] == val && !vis[row][col-1]) dfs(row, col-1, image2, vis, color, val);
        if(row-1 >= 0 && image2[row-1][col] == val && !vis[row-1][col]) dfs(row-1, col, image2, vis, color, val);
        if(col+1 < n && image2[row][col+1] == val && !vis[row][col+1]) dfs(row, col+1, image2, vis, color, val);
        if(row+1 < m && image2[row+1][col] == val && !vis[row+1][col]) dfs(row+1, col, image2, vis, color, val);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        vector<vector<int>> image2(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                image2[i][j] = image[i][j];
            }
        }

        dfs(sr, sc, image2, vis, color, image[sr][sc]);
        return image2;
    }
};