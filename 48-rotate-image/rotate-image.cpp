class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 90 = transpose + reverse row
        // 180 = reverse row + reverse column
        // 270 = transpose + reverse col

        int n = matrix.size();  //rows
        // Step 1: transpose
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: reverse each row
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

        
    }
};