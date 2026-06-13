class Solution {
public:
    class DisjointSet{
        public:
        vector<int> size, parent;

        DisjointSet(int n){
            size.resize(n+1, 1);
            parent.resize(n+1);

            for(int i=0; i<=n; i++){
                parent[i] = i;
            }
        }

        int findUPar(int node){
            if(node == parent[node]) return node;

            return parent[node] = findUPar(parent[node]);
        }

        void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v) return;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 0) continue;

                int drow[] = {0, -1, 0, 1};
                int dcol[] = {-1, 0, 1, 0};

                for(int i=0; i<4; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
                        if(grid[nrow][ncol] == 1){
                            int nodeNo = row * n + col;
                            int adjNodeNo = nrow * n + ncol;

                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }

        int mx = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 1) continue;

                int drow[] = {0, -1, 0, 1};
                int dcol[] = {-1, 0, 1, 0};
                set<int> components;

                for(int i=0; i<4; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
                        if(grid[nrow][ncol] == 1){
                            int nodeNo = row * n + col;
                            int adjNodeNo = nrow * n + ncol;

                            components.insert(ds.findUPar(adjNodeNo));
                        }
                    }
                }

                int size = 0;
                for(auto &it : components){
                    size += ds.size[it];
                }

                mx = max(mx, size+1);
            }
        }

        for(int i=0; i < n*n; i++){
            mx = max(mx, ds.size[ds.findUPar(i)]);
        }
        
        return mx;
    }
};