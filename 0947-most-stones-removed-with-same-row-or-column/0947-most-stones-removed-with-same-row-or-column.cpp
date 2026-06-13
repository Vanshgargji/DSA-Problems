class Solution {
public:
class DisjointSet{
        public:
        vector<int> rank, parent;

        DisjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);

            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }

        int findUPar(int node){
            if(node == parent[node]) return node;

            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;

            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
    };

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        DisjointSet ds(n);
        vector<vector<int>> edges;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    edges.push_back({i, j});
                }
            }
        }

        for(auto &it : edges){
            int u = it[0], v = it[1];
            if(ds.findUPar(u) != ds.findUPar(v)){
                ds.unionByRank(u, v);
            }
        }

        int components = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i) components++;
        }

        return n - components;
    }
};