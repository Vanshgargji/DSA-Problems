class Solution {
public:
    int reverseNum(int x){
        int y = 0; 
        while(x>0){
            int rem = x % 10;
            y = y * 10 + rem;
            x = x / 10;
        }
        return y;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> prev;
        int ans = n + 1;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (prev.count(x)) {
                ans = min(ans, i - prev[x]);
            }
            prev[reverseNum(x)] = i;
        }

        return ans == n + 1 ? -1 : ans;
        
    }
};