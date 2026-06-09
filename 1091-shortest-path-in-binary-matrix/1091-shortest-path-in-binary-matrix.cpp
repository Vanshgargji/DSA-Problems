class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;

        priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>
        > pq;
        
        pq.push({0, {0, 0}});

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 0;

        while(!pq.empty()){
            int row = pq.top().second.first;
            int col= pq.top().second.second;
            pq.pop();

            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    if(i==0 && j==0) continue;

                    int nrow = row + i;
                    int ncol = col + j;

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0){
                        if(dist[row][col] + 1 < dist[nrow][ncol]){
                            dist[nrow][ncol] = dist[row][col] + 1;
                            pq.push({dist[nrow][ncol], {nrow, ncol}});
                        }
                    }
                }
            }
        }
        
        return dist[n-1][n-1] != 1e9 ? dist[n-1][n-1] + 1 : -1;
    }
};