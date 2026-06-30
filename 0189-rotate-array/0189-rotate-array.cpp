class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n, 0);

        k = k % n;

        int idx = 0;

        for(int i=n-k; i<n; i++){
            temp[idx] = nums[i];
            idx++;
        }

        for(int i=0; i<n-k; i++){
            temp[idx] = nums[i];
            idx++;
        }
        
        nums = temp;
    }
};