class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int balanced = 0;
        stack<char> st;

        for(int i=0; i<s.size(); i++){
            st.push(s[i]);
            if(s[i] == '(') balanced++;
            else balanced--;
            
            if(balanced == 0){
                st.pop();
                string part = "";
                while(st.size() > 1){
                    part += st.top();
                    st.pop();
                }
                st.pop();
                reverse(part.begin(), part.end());
                ans += part;
            }
        }
        return ans;
    }
};