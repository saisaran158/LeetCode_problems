class Solution {
public:
    int mod = 1e9 + 7;
    int delr[2] = {0, 1};
    int delc[2] = {1, 0};
    bool check(int i, int j, int& m, int& n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }
    int rec(int r, int c, int& m, int& n, vector<vector<int>>& grid, int dir, vector<vector<vector<int>>>& dp) {
        if (r == m - 1 && c == n - 1)
            return 1;
        if(dp[r][c][dir + 1] != -1) return dp[r][c][dir + 1];
        int ans = 0;

        if (grid[r][c] == 1) {
            if (dir == 0) {
                if (check(r + 1, c, m, n)) {
                    ans = (ans + rec(r + 1, c, m, n, grid, 1, dp)) % mod;
                }
            } else if (dir == 1) {
                if (check(r, c + 1, m, n)) {
                    ans = (ans + rec(r, c + 1, m, n, grid, 0, dp)) % mod;
                }
            }
        } else if (grid[r][c] == 0) {
            for (int i = 0; i < 2; i++) {
                int nr = r + delr[i];
                int nc = c + delc[i];
                if (check(nr, nc, m, n)) {
                    ans = (ans + rec(nr, nc, m, n, grid, i, dp) % mod);
                }
            }
        }
        return dp[r][c][dir + 1] = ans % mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(3, -1)));
        return rec(0, 0, m, n, grid, -1, dp) % mod;
    }
};