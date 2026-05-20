class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int, int> mp;

        vector<int> ans;

        for(int i=0; i<n; i++){
            mp[A[i]]++;
            mp[B[i]]++;
            int count = 0;

            for(auto &it:mp){
                if(it.second > 1) count++;
            }

            ans.push_back(count);
        }
        
        return ans;
    }
};