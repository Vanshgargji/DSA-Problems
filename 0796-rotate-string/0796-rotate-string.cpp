class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        for(int i=0; i<s.size(); i++){
            char temp = s[0];
            for(int j=1; j<s.size(); j++){
                s[j-1] = s[j];
            };
            s[s.size()-1] = temp;

            if(s == goal) return true;
        }

        return false;
    }
};