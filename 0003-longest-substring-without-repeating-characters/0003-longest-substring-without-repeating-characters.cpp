class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;

        int n = s.size();
        int maxLen = INT_MIN;

        unordered_map<int, int> mp;

        int l = 0, r = 0;
        while(r < n){

            while(!mp.empty() && mp.count(s[r])){
                mp.erase(s[l]);
                l++;
            }

            mp[s[r]]++;

            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        
        return maxLen;
    }
};