class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> graph(V);

        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> indegree(V, 0);
        vector<int> ans;

        for(int i=0; i<V; i++){
            for(auto &it : graph[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto &it : graph[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        return ans.size() == V ? ans : vector<int>{};
    }
};