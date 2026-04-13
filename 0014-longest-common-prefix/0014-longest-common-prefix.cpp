class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = INT_MAX ;
        for(int i=0; i<strs.size(); i++){
            minLen = min(minLen, (int)strs[i].size());
        }

        while(minLen >= 0){
            bool flag = true;  
            for(int i=0; i<strs.size()-1; i++){
                if(strs[i].substr(0,minLen) != strs[i+1].substr(0, minLen)) {
                    flag = false;
                    break;
                }
            }
            if(flag) break;
            minLen--;
        }
        return strs[0].substr(0, minLen);
    }
};