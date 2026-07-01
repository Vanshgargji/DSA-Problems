class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int ans = -1;

        for(auto &i : nums){
            if(i != 0) cnt++;
            else{
                ans = max(ans, cnt);
                cnt = 0;
            }
        }

        ans = max(ans, cnt);

        return ans;
    }
};