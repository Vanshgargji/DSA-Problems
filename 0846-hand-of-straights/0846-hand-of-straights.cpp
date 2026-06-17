class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

    int n = hand.size();

    if(n % groupSize != 0) return false;

    unordered_map<int,int> freq;

    for(int x : hand)
        freq[x]++;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    for(auto &it : freq)
        pq.push({it.first, it.second});

    while(!pq.empty()) {

        vector<int> tempElement;
        vector<int> tempFreq;

        int start = pq.top().first;

        for(int i = 0; i < groupSize; i++) {

            if(pq.empty())
                return false;

            auto [ele, f] = pq.top();
            pq.pop();

            // consecutiveness check
            if(ele != start + i)
                return false;

            f--;

            tempElement.push_back(ele);
            tempFreq.push_back(f);
        }

        for(int i = 0; i < groupSize; i++) {
            if(tempFreq[i] > 0) {
                pq.push({tempElement[i], tempFreq[i]});
            }
        }
    }

    return true;
  }
};