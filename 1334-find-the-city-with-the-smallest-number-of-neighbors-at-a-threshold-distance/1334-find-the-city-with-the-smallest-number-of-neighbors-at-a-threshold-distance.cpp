class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n, vector<int>(n, 1e9));

        for(int i=0; i<n; i++){
            cost[i][i] = 0;
        }

        for(auto &it : edges){
            int u = it[0], v = it[1], wt = it[2];
            cost[u][v] = wt;
            cost[v][u] = wt;
        }

        for(int via=0; via<n; via++){

            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(cost[i][via] != 1e9 && cost[via][j] != 1e9){
                        cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
                    }
                }
            }
        }

        int minNeighbor = 1e9;
        int ans = -1;
        for(int i=0; i<n; i++){
            int cnt = 0; 

            for(int j=0; j<n; j++){
                if(i == j) continue;
                if(cost[i][j] <= distanceThreshold) cnt++;
            }

            if(cnt <= minNeighbor){
                minNeighbor = cnt;
                ans = i;
            }
        }
        
        return ans;
    }
};