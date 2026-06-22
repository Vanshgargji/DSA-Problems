class Solution {
public:
    void computeLps(string pattern, vector<int>& lps) {
        int M = pattern.length();
        int len = 0; // Length of the previous longest prefix & suffix
    
        lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]
    
        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; //You can also write, len = len-1;
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    string shortestPalindrome(string s) {
        int n = s.size();

        string rev = s;
        reverse(rev.begin(), rev.end());

        string temp = s + '-' + rev;
        vector<int> lps(temp.size(), 0);

        computeLps(temp, lps);

        int longestLpsLength = lps[temp.size() - 1];
        string culprit = rev.substr(0, s.size() - longestLpsLength);

        return culprit + s;
    }
};