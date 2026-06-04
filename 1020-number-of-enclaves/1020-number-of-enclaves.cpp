class Solution {
public:
    int m , n;

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        for(int i=0; i<n; i++){
            //first row
            if(grid[0][i] == 1){
                vis[0][i] = 1;
                q.push({0, i});
            }
            // last row
            if(grid[m-1][i] == 1){
                vis[m-1][i] = 1;
                q.push({m-1, i});
            }
        }

        for(int j=0; j<m; j++){
            //first column
            if(grid[j][0] == 1){
                vis[j][0] = 1;
                q.push({j, 0});
            }
            // last column
            if(grid[j][n-1] == 1){
                vis[j][n-1] = 1;
                q.push({j, n-1});
            }
        }

        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !vis[i][j]) count++;
            }
        }
        
        return count;
    }
};