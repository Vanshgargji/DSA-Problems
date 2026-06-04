class Solution {
public:
    int m, n;

    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid) {
        vis[row][col] = 1;

        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                vis[nrow][ncol] = 1;
                dfs(nrow, ncol, vis, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1 && !vis[0][i]) {
                dfs(0, i, vis, grid);
            }

            if (grid[m - 1][i] == 1 && !vis[m - 1][i]) {
                dfs(m - 1, i, vis, grid);
            }
        }

        for (int j = 0; j < m; j++) {
            if (grid[j][0] == 1 && !vis[j][0]) {
                dfs(j, 0, vis, grid);
            }

            if (grid[j][n - 1] == 1 && !vis[j][n - 1]) {
                dfs(j, n - 1, vis, grid);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
};