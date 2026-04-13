class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int ans = 1e9;

        for(int i=start; i>=0; i--){
            if(nums[i] == target){
                ans = min(ans, abs(i - start));
                break;
            }
        }

        for(int i=start+1; i<n; i++){
            if(nums[i] == target){
                ans = min(ans, abs(i - start));
                break;
            }
        }
        return ans;
    }
};