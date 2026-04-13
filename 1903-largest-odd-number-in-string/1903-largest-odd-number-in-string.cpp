class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size() - 1;
        while(i >= 0){
            if((num[i] - '0') % 2 != 0) break;
            i--;
        }

        string ans = "";
        for(int start = 0; start <= i; start++){
            ans += num[start];
        }
        return ans;
    }
};