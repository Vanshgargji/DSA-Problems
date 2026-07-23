class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans  = "";
        int balanced = 0;

        for(auto &c : s){
            if(c == '('){
                if(balanced > 0) ans += c;
                balanced++;
            }
            else{
                balanced--;
                if(balanced > 0) ans += c;
            }
        }

        return ans;
    }
};