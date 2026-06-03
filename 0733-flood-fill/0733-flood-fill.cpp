class Solution {
public:
    int m , n;

    void dfs(int row, int col, vector<vector<int>> &image2, vector<vector<int>> &vis, int color, int val){
        vis[row][col] = 1;
        image2[row][col] = color;

        int drow[] = {0, -1, 0, +1};
        int dcol[] = {-1, 0, +1, 0};

        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image2[nrow][ncol] == val && !vis[nrow][ncol]) dfs(nrow, ncol, image2, vis, color, val);
        }
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