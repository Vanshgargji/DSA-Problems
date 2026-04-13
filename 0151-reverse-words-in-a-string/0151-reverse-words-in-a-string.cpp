class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";

        for(int i=0; i < s.size(); i++){
            if(s[i]==' '){
                if(word.size() != 0) words.push_back(word);
                word = "";

                continue;
            }

            word += s[i];
        }

        if(word.size() != 0){
            words.push_back(word);
        }

        string ans = "";
        for(int j = words.size()-1; j>=0; j--){
            ans += words[j];
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};