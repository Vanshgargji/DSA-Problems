class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, 0);

        queue<int> q;

        for(int i=0; i<v; i++){
            if(color[i] != 0) continue;

            color[i] = 1; 
            q.push(i);

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto &it : graph[node]){
                    if(color[it] == 0){
                        color[it] = -color[node];
                        q.push(it);
                    }
                    else if(color[it] == color[node]) return false;
                }
            }
        }

        return true;
    }
};