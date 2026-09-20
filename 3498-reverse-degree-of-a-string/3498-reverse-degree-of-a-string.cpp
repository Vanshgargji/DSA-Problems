class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;

        for(int i = 0 ; i < s.size(); i++){
            char c = s[i];
            int revIndex = 26 - (c - 'a');
            sum += revIndex * (i + 1);
        }

        return sum;
    }
};