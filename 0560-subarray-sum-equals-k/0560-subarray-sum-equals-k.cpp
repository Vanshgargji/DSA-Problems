class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp.insert({0, 1});

        int cumSum = 0;
        int result = 0;

        for(auto &i : nums){
            cumSum += i;

            if(mp.count(cumSum - k)){
                result += mp[cumSum - k];
            }
            mp[cumSum]++;
        }

        return result;
    }
};