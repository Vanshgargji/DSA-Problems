class Solution {
public:
    int n;

    bool dfs(int node, vector<int> &vis, vector<int> &pathvis, vector<int> &ans, vector<vector<int>> &graph){
        vis[node] = 1;
        pathvis[node] = 1;

        for(auto &it : graph[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathvis, ans, graph) == true) return true;
            }
            else if(vis[it] && pathvis[it]) return true;
        }

        pathvis[node] = 0;
        ans.push_back(node);

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n = graph.size();

        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, pathvis, ans, graph);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};