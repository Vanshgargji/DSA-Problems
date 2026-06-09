class Solution {
public:
    int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> graph(n);

        for(auto &it : roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()){

            auto [dis, node] = pq.top();
            pq.pop();

            for(auto &it : graph[node]){

                int adjNode = it.first;
                int wt = it.second;

                if(dis + wt < dist[adjNode]){

                    dist[adjNode] = dis + wt;
                    ways[adjNode] = ways[node];

                    pq.push({dist[adjNode], adjNode});
                }
                else if(dis + wt == dist[adjNode]){

                    ways[adjNode] =
                        (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};