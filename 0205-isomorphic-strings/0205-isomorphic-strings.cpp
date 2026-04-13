class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1; // s to t 
        unordered_map<char, char> mp2; // t to s

        for(int i=0; i<s.size(); i++){
            char ch1 = s[i];
            char ch2 = t[i];

           if(mp1.count(ch1) && mp2[ch2] != ch1) return false;
           if(mp2.count(ch2) && mp1[ch1] != ch2) return false;

           mp1[ch1] = ch2;
           mp2[ch2] = ch1;
        }
        
        return true;
        // Learning: 
        // map syntax is mp.count() 
        // this is wrong mp.count[]
    }
};