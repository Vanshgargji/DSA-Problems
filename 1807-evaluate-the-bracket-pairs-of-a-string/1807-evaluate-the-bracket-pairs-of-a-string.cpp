class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (const auto& pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                string key = "";
                i++; // skip the '('
                while (i < s.size() && s[i] != ')') {
                    key += s[i];
                    i++;
                }
                // Check map and append replacement
                if (mp.count(key)) {
                    res += mp[key];
                } else {
                    res += '?';
                }
            } else {
                res += s[i];
            }
        }

        return res;
    }
};