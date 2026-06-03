class Solution {
public:
    int m;
    int n;

    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid) {
        queue<pair<int, int>> q;

        q.push({row, col});
        vis[row][col] = 1;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if (row - 1 >= 0 && grid[row - 1][col] == '1' && !vis[row - 1][col]) {
                q.push({row - 1, col});
                vis[row - 1][col] = 1;
            }

            if (row + 1 < m && grid[row + 1][col] == '1' && !vis[row + 1][col]) {
                q.push({row + 1, col});
                vis[row + 1][col] = 1;
            }

            if (col - 1 >= 0 && grid[row][col - 1] == '1' && !vis[row][col - 1]) {
                q.push({row, col - 1});
                vis[row][col - 1] = 1;
            }

            if (col + 1 < n && grid[row][col + 1] == '1' && !vis[row][col + 1]) {
                q.push({row, col + 1});
                vis[row][col + 1] = 1;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    bfs(i, j, vis, grid);
                    count++;
                }
            }
        }

        return count;
    }
};