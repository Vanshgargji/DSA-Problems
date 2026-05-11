class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;

        for(auto &num:nums){
            vector<int> digits;
            
            while(num > 0){
                int value = num % 10;
                digits.push_back(value);
                num = num / 10;
            }

            for(int i = digits.size() - 1; i>=0; i--){
                result.push_back(digits[i]);
            }
        }
        return result;
    }
};