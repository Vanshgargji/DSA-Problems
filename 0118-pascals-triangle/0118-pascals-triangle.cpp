class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return {};

        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1; i<numRows; i++){
            vector<int> temp;
            int prevRowSize = ans[i-1].size();

            temp.push_back(1);
            for(int j=1; j < prevRowSize; j++){
                temp.push_back(ans[i-1][j] + ans[i-1][j-1]);
            }
            temp.push_back(1);

            ans.push_back(temp);
        }

        return ans;
    }
};