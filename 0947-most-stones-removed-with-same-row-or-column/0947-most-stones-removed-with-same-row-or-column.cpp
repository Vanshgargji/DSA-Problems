class Solution {
public:
    void dfs(int node, vector<bool> &visited, vector<vector<int>> &adjList){
        visited[node] = true;

        for(auto &it : adjList[node]){
            if(!visited[it]){
                dfs(it, visited, adjList);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adjList(n);

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int components = 0;
        vector<bool> visited(n, false);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, visited, adjList);
                components++;
            }
        }

        return n - components;
    }
};