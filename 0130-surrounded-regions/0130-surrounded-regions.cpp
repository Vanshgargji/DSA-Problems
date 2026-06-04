class Solution {
public:
    int m , n;

    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board){
        vis[row][col] = 1;

        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};

        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >=0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                vis[nrow][ncol] = 1;
                dfs(nrow, ncol, vis, board);
            }

        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0; i<n; i++){
            // first row
            if(board[0][i] == 'O' && !vis[0][i]){
                dfs(0, i, vis, board);
            }
            // last row
            if(board[m-1][i] == 'O' && !vis[m-1][i]){
                dfs(m-1, i, vis, board);
            }
        }

        for(int j=0; j<m; j++){
            // first column
            if(board[j][0] == 'O' && !vis[j][0]){
                dfs(j, 0, vis, board);
            }
            // last column
            if(board[j][n-1] == 'O' && !vis[j][n-1]){
                dfs(j, n-1, vis, board);
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }

    }
};