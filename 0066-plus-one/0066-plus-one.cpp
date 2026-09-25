class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int carry = 1;
        vector<int> ans;

        for(int i=n-1; i>=0; i--){
            int val = digits[i] + carry;
            carry = val / 10;

            ans.push_back(val % 10);
        }
        
        if(carry) ans.push_back(carry);

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};