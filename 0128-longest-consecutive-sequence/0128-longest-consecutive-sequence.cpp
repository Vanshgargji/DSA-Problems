class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(auto &num : nums){
            st.insert(num);
        }

        int cnt = 0;
        int longest = 0;

        for(auto &i : st){
            if(!st.count(i-1)){
                int x = i;
                int cnt = 1;

                while(st.count(x+1)){
                    cnt++;
                    x++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};