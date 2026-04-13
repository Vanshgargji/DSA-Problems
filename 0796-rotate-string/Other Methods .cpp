class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        s += s;
        if(s.find(goal) != string::npos) return true;

        return false;
    }
};



class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        for(int i=0; i<s.size(); i++){
            rotate(s.begin(), s.begin() + 1, s.end());

            if(s == goal) return true;
        }

        return false;
    }
};







