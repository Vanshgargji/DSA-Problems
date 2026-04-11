class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return -1;

        int ans = INT_MAX;  // also fix this (important)

        int maxVal = *max_element(nums.begin(), nums.end());
        vector<vector<int>> group(maxVal + 1);  // ✅ FIX

        for(int i = 0; i < n; i++){
            group[nums[i]].push_back(i);
        }

        for(int i = 0; i < group.size(); i++){  // safer loop
            if(group[i].size() >= 3){
                sort(group[i].begin(), group[i].end());

                for(int j=0; j+2 < group[i].size(); j++){
                    int a = group[i][j];
                    int c = group[i][j+2];
                    ans = min(ans, 2 * (c - a));
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;  // handle no valid case
    }
};