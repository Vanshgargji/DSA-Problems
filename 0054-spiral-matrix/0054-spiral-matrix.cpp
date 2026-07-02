class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); //rows
        int n = matrix[0].size(); // cols

        vector<int> res;

        if(m == 0 || n == 0) return res;

        int up = 0, left = 0, right = n-1, down = m-1;

        while(res.size() < m*n){
            for(int i=left; i<=right && res.size() < m*n; i++){
                res.push_back(matrix[up][i]);
            }

            for(int i=up+1; i<=down-1 && res.size() < m*n; i++){
                res.push_back(matrix[i][right]);
            }

            for(int i=right; i>=left && res.size() < m*n; i--){
                res.push_back(matrix[down][i]);
            }

            for(int i=down-1; i>=up+1 && res.size() < m*n; i--){
                res.push_back(matrix[i][left]);
            }

            left++; right--; up++; down--;
        }

        return res;
    }
};