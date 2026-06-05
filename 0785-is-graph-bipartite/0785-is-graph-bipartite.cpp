class Solution {
public:
    int n;

    bool dfs(int node, vector<int> &color, vector<vector<int>> &graph){

        for(auto &it:graph[node]){
            if(color[it] == -1){
                color[it] = !color[node];
                if(dfs(it, color, graph) == false) return false;
            }
            else if(color[node] == color[it]) return false;
        }
  
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> color(n, -1);

        color[0] = 0;
        if(dfs(0, color, graph) == false) return false;

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(dfs(i, color, graph) == false) return false;
            } 
        }
        
        return true;
    }
};