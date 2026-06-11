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

    int makeConnected(int n, vector<vector<int>>& connections) {

        // for a graph to be connected minimum n-1 edges are required. 
        if(connections.size() < n-1){
            return -1;
        }

        DisjointSet ds(n);
        int freeEdges = 0;

        // O(E * 4 * alpha * 2)
        for(auto &it : connections){
            int u = it[0], v = it[1];
            
            if(ds.findUPar(u) == ds.findUPar(v)){
                freeEdges++;
            } else{
                ds.unionByRank(u, v);
            }
        }

        // find number of bosses to get no of components
        // O(N)
        int components = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i) components++;
        }

        if(components-1 <= freeEdges){
            return components - 1;
        } 

        return -1;
    }
};