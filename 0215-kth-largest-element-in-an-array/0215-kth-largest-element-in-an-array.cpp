class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // largest - min heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &i : nums){
            pq.push(i);

            if(pq.size() > k){
                pq.pop();
            }
        }

        return pq.top();
    }
};