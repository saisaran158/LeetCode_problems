class Solution {
public:
    int delr[2] = {0, 1};
    int delc[2] = {1, 0};
    int rec(int i, int j, int& m, int& n, int k, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp) {
        if (i == m - 1 && j == n - 1) {
            if (k > 0 && coins[i][j] < 0)
                return 0;
            else
                return coins[i][j];
        }
        if(dp[i][j][k] != -1e9) return dp[i][j][k];
        int ans = -1e9;
        if (coins[i][j] >= 0) {
            for (int l = 0; l < 2; l++) {
                int nr = i + delr[l];
                int nc = j + delc[l];
                if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                    ans = max(ans, coins[i][j] + rec(nr, nc, m, n, k, coins, dp));
                }
            }
        } 
        else if (coins[i][j] < 0) {
            for (int l = 0; l < 2; l++) {
                int nr = i + delr[l];
                int nc = j + delc[l];
                if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                    ans = max(ans, coins[i][j] + rec(nr, nc, m, n, k, coins, dp));
                    if(k > 0)
                    ans = max(ans, rec(nr, nc, m, n, k - 1, coins, dp));
                }
            }
        }
        return dp[i][j][k] = ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(3, -1e9)));
        return rec(0, 0, m, n, 2, coins, dp);
    }
};