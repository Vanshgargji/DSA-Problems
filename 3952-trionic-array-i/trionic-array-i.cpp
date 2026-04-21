class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        if(n == 3) return false;

        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]) return false;
        }

        int p, q;
        int i=0; 

        while(i+1 < n && nums[i] < nums[i+1]){
            i++;
        }

        p = i;

        while(i+1 < n && nums[i] > nums[i+1]){
            i++;
        }

        q = i;

        for(int i=q+1; i<n-1; i++){
            if(nums[i] > nums[i+1]) return false;
        }

        if(0 < p && p < q && q < n-1) return true;

        return false;
    }
};