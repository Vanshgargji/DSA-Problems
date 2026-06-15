class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto &it : nums){
            mp[it]++;
        }

        sort(nums.begin(), nums.end(), [&](auto &a, auto &b){
            if(mp[a] == mp[b]) return a > b;
            return mp[a] < mp[b];
        });

        return nums;
    }
};