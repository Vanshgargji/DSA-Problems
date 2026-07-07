class Solution {
public:
    long long sumAndMultiply(int n) {
        long long y = 0; 

        while(n > 0){
            int rem = n % 10;
            if(rem != 0)
                y = y * 10 + rem;
            n /= 10;
        }

        long long x = 0;  
        int sum = 0;     

        while(y > 0){
            int rem = y % 10;
            x = x * 10 + rem;  
            sum += rem;       
            y /= 10;
        }

        long long ans = sum * x;
        return ans;
    }
};