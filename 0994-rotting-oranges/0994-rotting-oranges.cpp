class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0; 
        int time = 0;

        vector<vector<int>> grid2 = grid;
        queue<pair<pair<int, int>, int>> q;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid2[i][j] == 2){
                    q.push({{i, j}, 0});
                }

                if(grid2[i][j] == 1) fresh++;
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;

            q.pop();
            
            time = max(time, t);

            int drow[] = {0, -1, 0, 1};
            int dcol[] = {-1, 0, 1, 0};

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid2[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, t+1});
                    grid2[nrow][ncol] = 2;
                    fresh--;
                }
            }
        }
        
        return fresh == 0 ? time : -1;
    }
};