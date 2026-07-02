class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for(auto &ch : s){
            mp[ch]++;
        }

        // max heap
        priority_queue<pair<int, char>> pq; // {freq, alphabet index}

        for(auto &p : mp){
            pq.push({p.second, p.first});
        }
        string ans = "";

        while(!pq.empty()){
            int f = pq.top().first;
            char c = pq.top().second;
            pq.pop();

            while(f--){
                ans += c;
            }
        }
        
        return ans;
    }
};