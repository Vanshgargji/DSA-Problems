class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;

        int total = n * m;
        vector<int> flat(total);

        // Step 1: Flatten grid
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                flat[i * m + j] = grid[i][j] % mod;
            }
        }

        // Step 2: Prefix products
        vector<int> prefix(total, 1), suffix(total, 1);

        for(int i = 1; i < total; i++) {
            prefix[i] = (prefix[i - 1] * flat[i - 1]) % mod;
        }

        // Step 3: Suffix products
        for(int i = total - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * flat[i + 1]) % mod;
        }

        // Step 4: Build result
        vector<vector<int>> ans(n, vector<int>(m));

        for(int i = 0; i < total; i++) {
            int val = (prefix[i] * suffix[i]) % mod;
            ans[i / m][i % m] = val;
        }

        return ans;
    }
};