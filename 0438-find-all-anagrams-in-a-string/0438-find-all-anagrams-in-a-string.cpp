class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if(p.size() > s.size()) return ans;

        vector<int> freqP(26, 0), window(26, 0);

        // Frequency of p
        for(char ch : p) {
            freqP[ch - 'a']++;
        }

        int k = p.size();

        // First window
        for(int i = 0; i < k; i++) {
            window[s[i] - 'a']++;
        }

        // Compare first window
        if(window == freqP)
            ans.push_back(0);

        // Sliding window
        for(int i = k; i < s.size(); i++) {

            // Add new character
            window[s[i] - 'a']++;

            // Remove old character
            window[s[i - k] - 'a']--;

            if(window == freqP)
                ans.push_back(i - k + 1);
        }

        return ans;
    }
};