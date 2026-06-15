class Solution {
public:
    typedef pair<long long, pair<int, int>> pp;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pp> pq;

        for (auto &point : points) {
            int x = point[0];
            int y = point[1];

            long long dist = 1LL * x * x + 1LL * y * y;

            pq.push({dist, {x, y}});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};