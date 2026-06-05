class Solution {
public:
    int n;

    bool check(int start, vector<int> &color, vector<vector<int>> &graph){
        
        queue<int> q;
        color[start] = 0;
        q.push(start);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &it:graph[node]){
                if(color[it] == -1){
                    color[it] = (color[node] == 0 ? 1 : 0);
                    q.push(it);
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> color(n, -1);

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(check(i, color, graph) == false) return false;
            } 
        }
        
        return true;
    }
};