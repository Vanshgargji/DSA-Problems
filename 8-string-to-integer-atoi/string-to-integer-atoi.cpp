class Solution {
public:
    bool isDigit(char ch){
        if(ch >= '0' && ch <= '9') return true;
        return false;
    }

    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        int sign = 1; // by default positive
        long long num = 0;

        while(i<n && s[i] == ' '){  // condition 1
            i++;
        }

        if(i<n && s[i] == '-'){  // condition 2
            sign = -1; 
            i++;
        } else if(i<n && s[i] == '+'){
            i++;
        }

        while(i<n && isDigit(s[i])){
            int digit = s[i] - '0';

            num = num * 10 + digit;  // condition 3

            if(sign * num >= INT_MAX) return INT_MAX;    // condition 4
            if(sign *num <= INT_MIN) return INT_MIN;
            i++;
        }
        
        return (int)sign * num ; 
    }
};