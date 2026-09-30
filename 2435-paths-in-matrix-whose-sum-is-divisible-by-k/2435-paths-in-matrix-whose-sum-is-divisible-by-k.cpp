class Solution {
public:
    int mod = 1e9 + 7;
    int delr[2] = {0, 1};
    int delc[2] = {1, 0};
    int rec(int i, int j, int& m, int& n, vector<vector<int>>& grid, int k, int sum, vector<vector<vector<int>>>& dp){
        if(i == m - 1 && j == n - 1){
            if((sum + grid[i][j]) % k == 0){
                return 1;
            }
            return 0;
        }
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        int ans = 0;
        for(int l = 0; l < 2; l++){
            int nr = i + delr[l];
            int nc = j + delc[l];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                ans = (ans + rec(nr, nc, m, n, grid, k, (sum + grid[i][j]) % k, dp)) % mod;
            }
        }
        return dp[i][j][sum] = ans % mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int tot = 0;
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return rec(0, 0, m, n, grid, k, 0, dp);
    }
};