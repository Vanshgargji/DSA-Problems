class Solution {
public:
    void computeLps(string s, vector<int> &lps){
        int n = s.size();

        lps[0] = 0;
        int len = 0;
        int i =1;

        while(i < n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    string longestPrefix(string s) {
        int n = s.size();

        vector<int> lps(n, 0);
        computeLps(s, lps);
        
        int maxi = lps[n - 1];
        
        return s.substr(0, maxi);
    }
};