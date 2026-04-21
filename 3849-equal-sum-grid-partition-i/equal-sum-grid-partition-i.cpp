class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(); // rows
        int n = grid[0].size(); // cols
        long long sum = 0; 

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                sum += grid[i][j];
            }
        }
        if(sum % 2 != 0) return false;
        
        long long rowWiseSum = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                rowWiseSum += grid[i][j];
            }
            if(rowWiseSum == sum / 2) return true;
        }

        long long colWiseSum = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                colWiseSum += grid[j][i];
            }
            if(colWiseSum == sum / 2) return true;
        }
        
        return false;
    }
};