class Solution {
public:
    int maxProduct(int n) {
        long long product = 0;
        int firstLargest = -1e9;
        int secondLargest = -1e9;

        while(n > 0){
            int digit = n % 10;

            if(digit >= firstLargest){
                secondLargest = firstLargest;
                firstLargest = digit;
            }
            else if(digit > secondLargest && digit < firstLargest){
                secondLargest = digit;
            }

            n = n / 10;
        }

        product = firstLargest * secondLargest;

        return product;
    }
};