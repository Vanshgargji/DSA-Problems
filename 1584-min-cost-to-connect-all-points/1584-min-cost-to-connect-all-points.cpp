class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        vector<int> vis(n, 0);
        vector<int> minDist(n, INT_MAX);

        pq.push({0, 0});
        minDist[0] = 0;

        int cost = 0;

        while(!pq.empty()) {
            auto [wt, u] = pq.top();
            pq.pop();

            if(vis[u]) continue;

            vis[u] = 1;
            cost += wt;

            for(int v = 0; v < n; v++) {
                if(!vis[v]) {
                    int dist = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);

                    if(dist < minDist[v]) {
                        minDist[v] = dist;
                        pq.push({dist, v});
                    }
                }
            }
        }

        return cost;
    }
};