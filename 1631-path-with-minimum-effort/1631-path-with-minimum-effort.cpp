class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>
        > pq;

        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};

        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == m-1 && col == n-1) return dist[row][col];

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >=0 && nrow < m && ncol >= 0 && ncol < n){
                    int maxeffort = max(abs(heights[row][col] - heights[nrow][ncol]), dist[row][col]);
                    
                    if(maxeffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = maxeffort;
                        pq.push({maxeffort, {nrow, ncol}});
                    }
                }
            }
        }
        
        return 0;
    }
};