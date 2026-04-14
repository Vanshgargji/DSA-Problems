// clean code using heap 
class Solution {
public:
    string frequencySort(string s) {
        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
        };
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        
        unordered_map<char, int> hm;
        
        for (char c : s) {
            hm[c]++;
        }
        
        for (const auto& entry : hm) {
            pq.push(make_pair(entry.first, entry.second));
        }
        
        string result = "";
        while (!pq.empty()) {
            pair<char, int> p = pq.top();
            pq.pop();
            result.append(p.second, p.first);
        }
        
        return result;
    }
};

//Approach-1 (Using Simple vector of pair and sorting it -  O(nlogn)
class Solution {
public:
    typedef pair<char, int> P;
    
    string frequencySort(string s) {
        vector<P> vec(123);
        
        for(char &ch : s) {
            int freq = vec[ch].second;
            vec[ch] = {ch, freq+1};
        }
        
        auto comp = [&](P &p1, P &p2) {
            return p1.second > p2.second;
        };
        
        sort(begin(vec), end(vec), comp);
        
        string result = "";
        
        for(int i = 0; i <= 122; i++) {
            result += string(vec[i].second, vec[i].first);
        }
        return result;
    }
};
