class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); //rows
        int n = matrix[0].size(); //cols

        queue<pair<int, int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0) q.push({i, j});
            }
        }

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            for(int i=0; i<n; i++){
                matrix[row][i] = 0;
            }

            for(int j=0; j<m; j++){
                matrix[j][col] = 0;
            }
        }
    }
};