class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int lastSmaller = -1e9;
        int maxi = 0;
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(nums[i] - 1 == lastSmaller){
                cnt++;
                lastSmaller = nums[i];
            }
            else if(nums[i] == lastSmaller){
                continue;
            }
            else if(nums[i] != lastSmaller){
                maxi = max(maxi, cnt);
                cnt = 1;
                lastSmaller = nums[i];
            }
        }

        maxi = max(maxi, cnt);

        return maxi;
    }
};