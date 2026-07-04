class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long totalElements = n * n; 
        
        long long sumN = (totalElements * (totalElements + 1)) / 2;
        long long sumSqN = (totalElements * (totalElements + 1) * (2 * totalElements + 1)) / 6;
        
        long long sumGrid = 0;
        long long sumSqGrid = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long long val = grid[i][j];
                sumGrid += val;
                sumSqGrid += (val * val);
            }
        }
        
        // x -> repeatingNo
        // y -> missingNo
        long long x_minus_y = sumGrid - sumN;
        long long x2_minus_y2 = sumSqGrid - sumSqN;
        
        long long x_plus_y = x2_minus_y2 / x_minus_y;
        
        long long x = (x_minus_y + x_plus_y) / 2;
        long long y = x - x_minus_y;
        
        return {(int)x, (int)y};
    }
};