class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto &it : flights){
            int u = it[0], v = it[1], wt = it[2];
            graph[u].push_back({v, wt});
        }

        queue<pair<int, pair<int, int>>> q;

        q.push({0, {src, 0}}); // {stops, {node, dist}}

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;

            q.pop();

            if(stops > k) continue;

            for(auto &it : graph[node]){
                int adjNode = it.first; 
                int price = it.second;

                if(dis + price < dist[adjNode]){
                    dist[adjNode] = dis + price;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        
        return dist[dst] != 1e9 ? dist[dst] : -1;
    }
};